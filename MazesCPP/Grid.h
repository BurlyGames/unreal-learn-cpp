/*
The Maze object
*/

#pragma once

#include "Cell.h"
#include <iostream>
#include <string>

// To make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

class Grid
{

public:

	Grid(int32 Rows, int32 Columns);

	void Reset();
	Cell GetCell(int32 Row, int32 Column);
	Cell GetRandomCell();
	int32 GetGridSize();
	// List<List<Cell>> GetRows();
	// List<Cell> GetCells();
	FString ContentsOf(Cell Cell);

private:

	// The 2D array of Cells is defined as a pointer to a pointer to an Cell (Cell**), and is set to point to array of pointers to Cells
	Cell** _cells;

	// The vertical height dimension of this Grid
	int32 _numRows;

	// The horizontal width dimension of this Grid
	int32 _numColumns;

	void Prepare();
	void Configure_Cells();
};

