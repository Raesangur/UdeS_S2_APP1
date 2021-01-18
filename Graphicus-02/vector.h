#pragma once
#include "forme.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <type_traits>

template<typename ItemType>
class vector
{
private:
    using Iterator = ItemType*;

    // m comme en privé
    Iterator m_begin    = nullptr;
    Iterator m_end      = nullptr;
    size_t   m_capacity = 0;

    void m_reallocate(size_t newCapacity);
    void m_reallocate();
    void m_removeElements(Iterator itBegin, Iterator itEnd);

public:
    vector() : m_begin(nullptr), m_end(nullptr), m_capacity(0)
    {
    }
    vector(size_t count);

    // Vecteur avec sa taille et assigne value a tous ses éléments
    vector(size_t count, const ItemType& value);

    // Copy constructor
    vector(const vector& other);

    // Destructeur
    ~vector();



    // Opérateur d'indexation pour accès
    // Activée si le type est un pointeur (SFINAE)
    template<typename T                                                     = ItemType,
             typename std::enable_if<std::is_pointer<T>::value, bool>::type = true>
    const T operator[](size_t index) const;

    // Activée si le type n'est pas un pointeur (SFINAE)
    template<typename T                                                      = ItemType,
             typename std::enable_if<!std::is_pointer<T>::value, bool>::type = true>
    const T& operator[](size_t index) const;

    ItemType& operator[](size_t index);

    Iterator begin() const;
    Iterator end() const;
    size_t   size() const;
    size_t   capacity() const;
    bool     empty() const;


    void resize(size_t newSize);
    void reserve(size_t capacity);
    void shrink_to_fit();


    // Appelle le destructeur sur tous les éléments
    // Réinitialise la taille à 0
    void     clear();
    void     push_back(const ItemType& value, size_t count = 1);
    void     pop_back(size_t count = 1);
    ItemType remove(size_t index);

    template<typename = std::enable_if<std::is_same<ItemType, Forme*>::value>>
    void afficher(std::ostream& s) const;
};


template<typename ItemType>
void vector<ItemType>::m_reallocate(size_t newCapacity)
{
    // Allocation du nouveau bloc de mémoire
    ItemType* newData    = new ItemType[newCapacity];
    size_t    copiedSize = std::min(newCapacity, size());
    resize(copiedSize);

    // Copie des données
    for(size_t i = 0; i < copiedSize; i++)
    {
        newData[i] = m_begin[i];
    }

    // Suppression de l'ancien bloc de mémoire
    delete[] m_begin;
    m_begin    = newData;
    m_end      = m_begin + copiedSize;
    m_capacity = newCapacity;
}

template<typename ItemType>
void vector<ItemType>::m_reallocate()
{
    m_reallocate(m_capacity * 2);
}

template<typename ItemType>
void vector<ItemType>::m_removeElements(Iterator itBegin, Iterator itEnd)
{
    for(Iterator it = itBegin; it < itEnd; it++)
    {
        // Normalement, std::destroy devrait être utilisé, ou un allocator comme std::allocator
        // pour pouvoir gérer la destruction des éléments et la déallocation.
        if constexpr(std::is_pointer<ItemType>::value == true)
        {
            // Ne fonctionne pas si le pointeur pointe vers un tableau
            // Undefined Behavior si le pointeur n'est pas alloué dynamiquement.
            delete *it;
        }
        else
        {
            it->~ItemType();
        }
    }
}

template<typename ItemType>
vector<ItemType>::vector() : m_begin(nullptr), m_end(nullptr), m_capacity(0)
{
}

template<typename ItemType>
vector<ItemType>::vector(size_t count)
{
    m_reallocate(count);
    resize(count);
}

// Vecteur avec sa taille et assigne value a tous ses éléments
template<typename ItemType>
vector<ItemType>::vector(size_t count, const ItemType& value)
{
    m_reallocate(count);
    resize(count);
    for(Iterator i = m_begin; i < m_end; i++)
    {
        *i = value;
    }
}

// Copy constructor
template<typename ItemType>
vector<ItemType>::vector(const vector& other)
{
    m_reallocate(other.capacity());
    resize(other.size());
    Iterator srcI = other.begin();
    for(Iterator destI = m_begin; destI < m_end; destI++, srcI++)
    {
        *destI = *srcI;
    }
}

// Destructeur
template<typename ItemType>
vector<ItemType>::~vector()
{
    clear();
    delete[] m_begin;
}



// Opérateur d'indexation pour accès
// Activée si le type est un pointeur (SFINAE)
template<typename ItemType>
template<typename T                                                     = ItemType,
         typename std::enable_if<std::is_pointer<T>::value, bool>::type = true>
const T vector<ItemType>::operator[](size_t index) const
{
    if(index >= size())
    {
        return nullptr;
    }
    return m_begin[index];
}

// Activée si le type n'est pas un pointeur (SFINAE)
template<typename ItemType>
template<typename T                                                      = ItemType,
         typename std::enable_if<!std::is_pointer<T>::value, bool>::type = true>
const T& vector<ItemType>::operator[](size_t index) const
{
    if(index >= size())
    {
        throw std::exception();
    }
    return m_begin[index];
}


template<typename ItemType>
ItemType& vector<ItemType>::operator[](size_t index)
{
    return operator[](index);
}

template<typename ItemType>
typename vector<ItemType>::Iterator vector<ItemType>::begin() const
{
    return m_begin;
}

template<typename ItemType>
typename vector<ItemType>::Iterator vector<ItemType>::end() const
{
    return m_end;
}

template<typename ItemType>
size_t vector<ItemType>::size() const
{
    return m_end - m_begin;
}

template<typename ItemType>
size_t vector<ItemType>::capacity() const
{
    return m_capacity;
}

template<typename ItemType>
bool vector<ItemType>::empty() const
{
    return size() == 0;
}

template<typename ItemType>
void vector<ItemType>::resize(size_t newSize)
{
    if(newSize < size())
    {
        m_removeElements(begin() + newSize, end());
    }

    m_end = m_begin + newSize;
}

template<typename ItemType>
void vector<ItemType>::reserve(size_t capacity)
{
    m_reallocate(capacity);
}

template<typename ItemType>
void vector<ItemType>::shrink_to_fit()
{
    m_reallocate(size());
}


// Appelle le destructeur sur tous les éléments
// Réinitialise la taille à 0
template<typename ItemType>
void vector<ItemType>::clear()
{
    m_removeElements(begin(), end());
    m_end = begin();
}

template<typename ItemType>
void vector<ItemType>::push_back(const ItemType& value, size_t count = 1)
{
    if(size() + count > capacity())
    {
        if(size() + count > capacity() * 2)
        {
            m_reallocate(size() + count);
        }
        else
        {
            m_reallocate();
        }
    }

    for(Iterator newEnd = m_end + count; m_end < newEnd; m_end++)
    {
        *m_end = value;
    }
}

template<typename ItemType>
void vector<ItemType>::pop_back(size_t count = 1)
{
    if(count > size())
    {
        return;
    }
    resize(size() - count);
}

template<typename ItemType>
ItemType vector<ItemType>::remove(size_t index)
{
    if(index > size())
    {
        return ItemType();
    }
    ItemType temp = m_begin[index];
    for(Iterator it = begin() + index; it < end() - 1; it++)
    {
        *it = *(it + 1);
    }
    m_end--;
    m_begin[size()].~ItemType();

    return temp;
}

// Méthode afficher qui n'existe que si le type est un Forme* (SFINAE)
template<typename ItemType>
template<typename = std::enable_if<std::is_same<ItemType, Forme*>::value>::type = true>
void vector<ItemType>::afficher(std::ostream& s) const
{
    for(Iterator it = begin(); it < end(); it++)
    {
        (*it)->afficher(s);
    }
}