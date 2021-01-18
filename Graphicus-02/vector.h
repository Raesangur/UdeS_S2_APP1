#ifndef VECTOR_H_
#define VECTOR_H_

#include "forme.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <type_traits>



template<typename ItemType, bool shouldDelete = std::is_pointer<ItemType>::value>
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

    inline void afficher(std::ostream& s) const;
};


template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::m_reallocate(size_t newCapacity)
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

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::m_reallocate()
{
    m_reallocate(m_capacity * 2);
}

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::m_removeElements(Iterator itBegin, Iterator itEnd)
{
    for(Iterator it = itBegin; it < itEnd; it++)
    {
        // Normalement, std::destroy devrait être utilisé, ou un allocator comme std::allocator
        // pour pouvoir gérer la destruction des éléments et la déallocation.
        if constexpr(shouldDelete == true && std::is_pointer<ItemType>::value)
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


template<typename ItemType, bool shouldDelete>
vector<ItemType, shouldDelete>::vector(size_t count)
{
    m_reallocate(count);
    resize(count);
}

// Vecteur avec sa taille et assigne value a tous ses éléments
template<typename ItemType, bool shouldDelete>
vector<ItemType, shouldDelete>::vector(size_t count, const ItemType& value)
{
    m_reallocate(count);
    resize(count);
    for(Iterator i = m_begin; i < m_end; i++)
    {
        *i = value;
    }
}

// Copy constructor
template<typename ItemType, bool shouldDelete>
vector<ItemType, shouldDelete>::vector(const vector& other)
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
template<typename ItemType, bool shouldDelete>
vector<ItemType, shouldDelete>::~vector()
{
    clear();
    delete[] m_begin;
}



// Opérateur d'indexation pour accès
// Activée si le type est un pointeur (SFINAE)
template<typename ItemType, bool shouldDelete>
template<typename T, typename std::enable_if<std::is_pointer<T>::value, bool>::type>
const T vector<ItemType, shouldDelete>::operator[](size_t index) const
{
    if(index >= size())
    {
        return nullptr;
    }
    return m_begin[index];
}

// Activée si le type n'est pas un pointeur (SFINAE)
template<typename ItemType, bool shouldDelete>
template<typename T, typename std::enable_if<!std::is_pointer<T>::value, bool>::type>
const T& vector<ItemType, shouldDelete>::operator[](size_t index) const
{
    if(index >= size())
    {
        throw std::exception();
    }
    return m_begin[index];
}

template<typename ItemType, bool shouldDelete>
ItemType& vector<ItemType, shouldDelete>::operator[](size_t index)
{
    return operator[](index);
}


template<typename ItemType, bool shouldDelete>
typename vector<ItemType, shouldDelete>::Iterator vector<ItemType, shouldDelete>::begin() const
{
    return m_begin;
}

template<typename ItemType, bool shouldDelete>
typename vector<ItemType, shouldDelete>::Iterator vector<ItemType, shouldDelete>::end() const
{
    return m_end;
}

template<typename ItemType, bool shouldDelete>
size_t vector<ItemType, shouldDelete>::size() const
{
    return m_end - m_begin;
}

template<typename ItemType, bool shouldDelete>
size_t vector<ItemType, shouldDelete>::capacity() const
{
    return m_capacity;
}

template<typename ItemType, bool shouldDelete>
bool vector<ItemType, shouldDelete>::empty() const
{
    return size() == 0;
}

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::resize(size_t newSize)
{
    if(newSize < size())
    {
        m_removeElements(begin() + newSize, end());
    }

    m_end = m_begin + newSize;
}

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::reserve(size_t capacity)
{
    m_reallocate(capacity);
}

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::shrink_to_fit()
{
    m_reallocate(size());
}


// Appelle le destructeur sur tous les éléments
// Réinitialise la taille à 0
template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::clear()
{
    m_removeElements(begin(), end());
    m_end = begin();
}

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::push_back(const ItemType& value, size_t count)
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

template<typename ItemType, bool shouldDelete>
void vector<ItemType, shouldDelete>::pop_back(size_t count)
{
    if(count > size())
    {
        return;
    }
    resize(size() - count);
}

template<typename ItemType, bool shouldDelete>
ItemType vector<ItemType, shouldDelete>::remove(size_t index)
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

// Méthode afficher qui n'existe que si le type est un Forme* (spécialisation de template)
// Le keyword inline sert à indiquer que la définition sera présente dans plusieurs translation
// units sans briser la one-definition-rule (on aurait du mettre la spécialisation de la template
// dans un fichier .cpp, mais elle aurait été seule)
template<>
inline void vector<Forme*>::afficher(std::ostream& s) const
{
    for(Forme* fp : *this)
    {
        fp->afficher(s);
    }
    // for(Iterator it = begin(); it < end(); it++)
    // {
    //     (*it)->afficher(s);
    // }
}


#endif
