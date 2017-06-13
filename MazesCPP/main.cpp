// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Grid.h"

int main()
{
	// NOTE on getting the Dimension sizes at runtime
	// No clear way to get the dimension size of dynamically allocated arrays at runtime.
	// Keep track of the dimensioned size with the object.  Or add an extra element to the array, stash the size at p, and return p+1 to point to the array.

	Grid _grid = Grid(10, 10);

	// BinaryTree maze algorithm



	//public static Grid Load(Grid grid)
	//{
	//	var rand = new Random();

	//	foreach(var cell in grid.GetCells())
	//	{
	//		// Build up a list of the North and East neighbors
	//		var neighbors = new List<Cell>();
	//		if (cell.North != null) neighbors.Add(cell.North);
	//		if (cell.East != null) neighbors.Add(cell.East);

	//		// Pick a random entry from North or East
	//		if (neighbors.Count > 0)
	//		{
	//			var pick = rand.Next(1, neighbors.Count + 1);

	//			// Link the random entry
	//			cell.Link(neighbors[pick - 1], true);
	//		}
	//	}

	//	return grid;
	//}





	_grid.OutputString();

	// Keep the window open
	std::cin.get();
	return 0;
}

