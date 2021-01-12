#pragma once
#include <cstddef>


template<typename ItemType>
class vector
{
private:
	using Iterator = ItemType*;

	Iterator m_begin = nullptr;
	Iterator m_end = nullptr;
	size_t   m_capacity = 0;

	void m_reallocate(size_t newCapacity)
	{
		ItemType* newData = new ItemType[newCapacity];
	}

public:
	vector(size_t count);
	vector(size_t count, const ItemType& value);
	vector(const vector& other);
	~vector();

	ItemType& operator[](size_t index);
	Iterator begin();
	Iterator end();

	size_t size();
	size_t capacity();
	void reserve(size_t capacity);
	void shrink_to_fit();

	void clear();
	void push_back(const ItemType& value, size_t count = 1);
	void pop_back(size_t count = 1);
};

