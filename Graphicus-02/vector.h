#pragma once
#include <algorithm>
#include <cstddef>

template<typename ItemType>
class vector
{
private:
    using Iterator = ItemType*;

    // m comme en privé
    Iterator m_begin    = nullptr;
    Iterator m_end      = nullptr;
    size_t   m_capacity = 0;

    void m_reallocate(size_t newCapacity)
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

    void m_reallocate()
    {
        m_reallocate(m_capacity * 2);
    }


public:
    vector(size_t count)
    {
        m_reallocate(count);
        resize(count);
    }

    // Vecteur avec sa taille et assigne value a tous ses éléments
    vector(size_t count, const ItemType& value)
    {
        m_reallocate(count);
        resize(count);
        for(Iterator i = m_begin; i < m_end; i++)
        {
            *i = value;
        }
    }

    // Copy constructor
    vector(const vector& other)
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
    ~vector()
    {
        clear();
        delete[] begin();
    }


    // Opérateur d'indexation pour accès
    ItemType& operator[](size_t index)
    {
        return m_begin[index];
    }

    Iterator begin()
    {
        return m_begin;
    }

    Iterator end()
    {
        return m_end;
    }

    size_t size()
    {
        return m_end - m_begin;
    }

    size_t capacity()
    {
        return m_capacity;
    }


    void resize(size_t newSize)
    {
        if(newSize < size())
        {
            for(Iterator it = m_begin + newSize; it < end(); it++)
            {
                // Appelle destructeur sur tous les éléments qui sont excédentaires
                it->~ItemType();
            }
        }

        m_end = m_begin + newSize;
    }

    void reserve(size_t capacity)
    {
        m_reallocate(capacity);
    }

    void shrink_to_fit()
    {
        m_reallocate(size());
    }


    // Appelle le destructeur sur tous les éléments
    // Réinitialise la taille à 0
    void clear()
    {
        for(Iterator it = begin(); it < end(); it++)
        {
            it->~ItemType();
        }
        m_end = begin();
    }

    void push_back(const ItemType& value, size_t count = 1)
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

    void pop_back(size_t count = 1)
    {
        resize(size() - count);
    }
};
