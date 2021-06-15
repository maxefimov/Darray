#pragma once
#include <time.h>
template <class T>
class Darray
{
	int length;
	int realsize;

	T* item;

	void resize()
	{
		T* temp = new T[realsize]{};
		for (int i = 0; i < length; i++)
			temp[i] = item[i];

		delete[]item;
		item = temp;
	}

public:
	Darray()
	{
		length = 0;
		realsize = 2;
		item = new T[realsize]{};
	}
	Darray(int size)
	{
		length = size;
		realsize = 2 * size;
		item = new T[realsize]{};
	}

	Darray(const Darray<T>& array)
	{
		*this = array;
	}

	Darray<T> operator=(const Darray<T> array)
	{
		if (&array == this)
			return;

		if (item)
			delete[]item;

		if (&array == nullptr)
		{
			this->length = 0;
			this->realsize = 2;
			item = new T[realsize]{};
			return;
		}

		this->realsize = array.realsize;
		this->length = array.length;

		item = new T[realsize]{};

		for (int i = 0; i < length; i++)
			item[i] = array.item[i];
	}

	~Darray()
	{
		if(item)
			delete[]item;
	}
	int Length()
	{
		return length;
	}
	void Insert(int index, T value)
	{
		if (length >= realsize)
		{
			realsize = realsize + realsize / 2;
			resize();
		}

		T* temp = new T[realsize];
		for (int i = 0; i < index; i++)
			temp[i] = item[i];
		temp[index] = value;
		for (int i = index; i < length; i++)
			temp[i + 1] = item[i];

		delete[]item;
		item = temp;
		length++;
	}

	T Remove(int index)
	{
		T value{ item[index] };

		if (length <= realsize / 2)
		{
			realsize = realsize - length / 2;
			resize();
		}

		T* temp = new T[realsize]{};
		for (int i = 0; i < index; i++)
			temp[i] = item[i];
		for (int i = index + 1; i < length; i++)
			temp[i - 1] = item[i];
		
		length--;

		delete[]item;
		item = temp;

		return value;
	}

	void PushBack(T value)
	{
		if (length >= realsize)
		{
			realsize = realsize + realsize / 2;
			resize();
		}
		item[length++] = value;
	}

	T PopBack()
	{
		T value{ item[--length] };

		if (length <= realsize / 2)
		{
			realsize = realsize - length / 2;
			resize();
		}

		return value;
	}

	T& At(int index)
	{
		return item[index];
	}

	T& operator[](int index)
	{
		return item[index];
	}

	void RandomInit(int begin, int end)
	{
		srand(time(nullptr));
		for (int i = 0; i < length; i++)
			item[i] = begin + rand() % (end - begin + 1);
	}

	void Print()
	{
		for (int i = 0; i < length; i++)
			std::cout << item[i] << " ";
		std::cout << "\n";
	}
};

