#pragma once
#include <algorithm>
#include <cstddef>
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


    void m_removeElements(Iterator itBegin, Iterator itEnd)
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
                // Appelle destructeur sur tous les éléments qui sont excédentaires
                it->~ItemType();
            }
        }
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
        delete[] m_begin;
    }

    // Opérateur d'indexation pour accès
    ItemType operator[](size_t index)
    {
        if(index > size())
        {
            return ItemType();
        }
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
    bool empty()
    {
        return size() == 0;
    }


    void resize(size_t newSize)
    {
        if(newSize < size())
        {
            m_removeElements(begin() + newSize, end());
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
        m_removeElements(begin(), end());
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
        if(count > size())
        {
            return;
        }
        resize(size() - count);
    }

    ItemType remove(size_t index)
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
        m_begin[--m_end].~ItemType();
    }
};
