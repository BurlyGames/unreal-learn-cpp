// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Grid.h"

int main()
{
	// The 1D array is defined as a pointer to an array of ints
	// The 2D array is defined as a pointer to a pointer to an int (int**), and is set to point to array of pointers to ints
	// The 3D array is defined as a pointer to a pointer to a pointer of an int (int***), and is set to point to an array 

	// NOTE on getting the Dimension sizes at runtime
	// No clear way to get the dimension size of dynamically allocated arrays at runtime.
	// Keep track of the dimensioned size with the object.  Or add an extra element to the array, stash the size at p, and return p+1 to point to the array.

	Grid _grid = Grid(10, 10);
	_grid.OutputString();


	// This pattern for dynamically-allocated, multi-dimensional arrays
	// type* ipArray for a 1-dimensional array of that type
	// type** ippArray for a 2-dimensional array of that type
	// type*** ipppArray for a 3-dimensional array of that type
	// type**** ippppArray for a 4-dimensional array of that type
	// etc.

	int _numRows = 10;
	int _numColumns = 3;

	// Initialize a two-dimensional array of ints
	int** ippArray = new int*[_numRows];
	for (int i = 0; i < _numRows; i++)
	{
		ippArray[i] = new int[_numColumns];
	}

	// Fill the array with values
	for (int i = 0; i < _numRows; i++)
	{
		for (int j = 0; j < _numColumns; j++)
		{
			ippArray[i][j] = i + j;
		}
	}

	// Output the array
	for (int i = 0; i < _numRows; i++)
	{
		for (int j = 0; j < _numColumns; j++)
		{
			std::cout << ippArray[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	// Deallocate the array
	for (int i = 0; i < _numRows; i++)
	{
		delete[] ippArray[i];
	}
	delete[] ippArray;

	// Keep the window open
	std::cin.get();
	return 0;
}

