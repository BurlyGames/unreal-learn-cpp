/*
An individual Cell object
*/

#pragma once
#include <string>

// To make the syntax Unreal friendly
using FString = std::string;
using int32 = int;

class Cell
{
public:

	// Constructors
	Cell();
	Cell(int32 Row, int32 Column, FString Name);

	FString Name;

	// Members
	Cell* North;
	Cell* South;
	Cell* East;
	Cell* West;

	// public Dictionary<Cell, bool> Links{ get; set; }

	// Methods
	bool IsLinked(Cell);
	void Link(Cell, bool);
	void Unlink(Cell, bool);
	// List<Cell> Neighbors();
	// Distances GetDistances();

private:

	int32 _row, _column;
	FString _name;

	// private Cell[,] _cells;

	Cell* _north;
	Cell* _south;
	Cell* _east;
	Cell* _west;
};

