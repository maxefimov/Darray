#include <iostream>
#include <time.h>
#include "Darray.h"

using namespace std;

void arrayInit(int* array, int size);
void arrayPrint(int* array, int size);
void arrayInsert(int*& array, int &size, int index, int value);
void arrayRemove(int*& array, int& size, int index);

int main()
{
	Darray<int> darr(10);

	/*darr.Print();
	darr.RandomInit(10, 120);
	darr.Print();
	darr.Insert(5, 200);
	darr.At(2) = 500;
	darr[3] = 600;
	darr.Print();*/

	int size{ 10 };
	int* array = new int[size];
	arrayInit(array, size);
	arrayPrint(array, size);
	arrayInsert(array, size, 5, 100);
	arrayPrint(array, size);
	arrayRemove(array, size, 7);
	arrayPrint(array, size);
	return 0;
}

void arrayInit(int* array, int size)
{
	srand(time(nullptr));
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}

void arrayPrint(int* array, int size)
{
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << "\n";
}

void arrayInsert(int*& array, int &size, int index, int value)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < index; i++)
		temp[i] = array[i];
	temp[index] = value;
	for (int i = index; i < size; i++)
		temp[i + 1] = array[i];
	
	delete[]array;
	array = temp;

	size++;
}

void arrayRemove(int*& array, int& size, int index)
{
	int* temp = new int[size - 1];
	for (int i = 0; i < index; i++)
		temp[i] = array[i];
	for (int i = index + 1; i < size; i++)
		temp[i - 1] = array[i];

	delete[]array;
	array = temp;

	size--;
}

void myswap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}