#pragma once
#include <iostream>
#include <string>

template <class TYPE>
class vector
{
private:
	int theSize, theCapacity;
	int * INDEX;

public:
	TYPE * dynArray;

	vector()
	{
		theSize = 0;
		theCapacity = 0;
		dynArray = new TYPE[theCapacity];
		vector * dynArray;
	}

	vector(int x)
	{
		theSize = x;
		theCapacity = x;
		dynArray = new TYPE[theCapacity];
		if (typeid(TYPE) == typeid(string))
		{
			for (int i = 0; i < theCapacity; i++)
				dynArray[i] = NULL;
		}
		else
		{
			for (int i = 0; i < theCapacity; i++)
				dynArray[i] = 0;
		}
		vector * dynArray;
	}

	vector(int x, TYPE y) //Fills up the array/vector why y, into each x.
	{
		theSize = x;
		theCapacity = x;
		dynArray = new TYPE[theCapacity];

		for (int i = 0; i < theCapacity; i++)
			dynArray[i] = y;
		vector * dynArray;
	}

	TYPE& operator[](int index) //Overloading the operator "[]"
	{
		return (this->dynArray[index]);
	}

	int size() //Used allocation
	{
		return theSize;
	}

	int capacity() //Full size allocation
	{
		return theCapacity;
	}

	void push_back(TYPE x) //Add element to end
	{
		if(theSize == theCapacity)
			resize();

		dynArray[theSize] = x;

		theSize++;
	}

	void pop_back()
	{
		theSize--;
	}

	TYPE back() //Look at last element in vector
	{
		return dynArray[theSize - 1]; //theSize - 1: Due to "theSize" always being 1 bigger than the index of the latest item in array.
	}
	
	void resize()
	{
		if (theCapacity == 0) //If full & not initialized to anything (zero)
 			theCapacity = 10;

		else
			theCapacity = theCapacity * 2;

		TYPE * temp = new TYPE[theCapacity];

		for (int i = 0; i < theSize; i++)
			temp[i] = dynArray[i];

		delete[] dynArray;
		dynArray = temp;
	}
	
};

