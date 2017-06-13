/*
The Grid object implementation
*/

#pragma once

#include "Grid.h"
#include <iostream>
#include <new>

using int32 = int;

Grid::Grid(int32 Rows, int32 Columns)
{
	_numRows = Rows;
	_numColumns = Columns;

	Grid::Prepare();
	Grid::Configure_Cells();
}

// Set up a fresh 2D array of Cell instances
void Grid::Prepare()
{
	_cells = new Cell*[Grid::_numRows];

	int32 _roomNumber = 0;

	// Run through each row, create a Cell array for each
	for (int row = 0; row < Grid::_numRows; row++)
	{
		_cells[row] = new Cell[Grid::_numColumns]; // Does this call the constructor on these Cells?

		// Initialize each Cell
		for (int col = 0; col < Grid::_numColumns; col++)
		{
			_cells[row][col] = Cell(row, col, "Room " + std::to_string(_roomNumber++));
		}
	}

	return;
}

// Tells each Cell who its immediate neighbors are to the north, south, east, and west
void Grid::Configure_Cells()
{
	for (int row = 0; row < Grid::_numRows; row++)
	{
		for (int col = 0; col < Grid::_numColumns; col++)
		{
			// If not in the first row, then the "north" cell is the previous row, same column
			if (row > 0)
				_cells[row][col].North = &_cells[row - 1][col];
			else
				_cells[row][col].North = NULL;

			// If we're not in the last row, then the "south" cell is the next row, same column
			if ((row + 1) < Grid::_numRows)
				_cells[row][col].South = &_cells[row + 1][col];
			else
				_cells[row][col].South = NULL;

			// If we're not in the first column, then the "west" cell is the same row, previous column
			if (col > 0)
				_cells[row][col].West = &_cells[row][col - 1];
			else
				_cells[row][col].West = NULL;

			// If we're not in the last column, then the "east" cell is the same row, next column
			if ((col + 1) < Grid::_numColumns)
				_cells[row][col].East = &_cells[row][col + 1];
			else
				_cells[row][col].East = NULL;
		}
	}

	return;
}

Cell Grid::GetCell(int32 Row, int32 Column)
{
	return Grid::_cells[Row][Column];
}

int32 Grid::GetGridSize()
{
	return _numRows * _numColumns;
}

FString Grid::ContentsOf(Cell Cell)
{
	return FString(Cell.Name);
}

void Grid::OutputString()
{
	std::cout << "\n\n";

	// Top Edge
	std::cout << "+";
	for (int i = 0; i < Grid::_numColumns; i++)
	{
		std::cout << "---+";
	}
	std::cout << "\n";

	// Each Row
	for (int row = 0; row < Grid::_numRows; row++)
	{
		FString topline = "|";
		FString bottomLine = "+";

		for (int col = 0; col < Grid::_numColumns; col++)
		{
			// If East is linked then open, else a wall edge
			//FString body = " " + Grid::_cells[row][col].Name + " ";
			FString body = "   ";
			FString east_boundary = "|";
			topline += body + east_boundary;

			// If South is linked then open, else a wall edige
			FString south_boundary = "---";
			FString corner = "+";
			bottomLine += south_boundary + corner;
		}

		std::cout << topline << "\n";
		std::cout << bottomLine << "\n";
	}

	std::cout << "\n\n";

	return;
}
