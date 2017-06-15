// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <random>
#include "Grid.h"

int main()
{
	// NOTE on getting the Dimension sizes at runtime
	// No clear way to get the dimension size of dynamically allocated arrays at runtime.
	// Keep track of the dimensioned size with the object.  Or add an extra element to the array, stash the size at p, and return p+1 to point to the array.

	Grid* _grid = new Grid(10, 10);

	// BinaryTree maze algorithm
	std::default_random_engine generator;

	// Loop through each cell
	for (int row = 0; row < _grid->NumRows(); row++)
	{
		for (int col = 0; col < _grid->NumColumns(); col++)
		{
			// Build up a list of the North and East neighbors
			std::vector<Cell*> _neighbors(4);
			int32 _neighborCount = 0;

			Cell* target = &_grid->Cells()[row][col];

			// If there is a cell to the North, then add it
			if (_grid->Cells()[row][col].North != NULL)
			{
				_neighbors.insert(_neighbors.begin(), _grid->Cells()[row][col].North);
				_neighborCount++;
			}

			// If there is a cell to the East, then add it
			if (_grid->Cells()[row][col].East != NULL)
			{
				_neighbors.insert(_neighbors.begin(), _grid->Cells()[row][col].East);
				_neighborCount++;
			}

			// Pick an item at random from the N/E neighbors
			if (_neighborCount > 0)
			{
				std::uniform_int_distribution<int> distribution(0, _neighborCount - 1);
				int dice_roll = distribution(generator);

				target->Link(_neighbors[dice_roll]);
				_neighbors[dice_roll]->Link(target);
			}
		}
	}

	_grid->OutputString();

	// Keep the window open
	std::cin.get();
	return 0;
}

