/*
The individual Cell object implementation
*/

#include "Cell.h"


Cell::Cell()
{
	return;
}

Cell::Cell(int32 Row, int32 Column, FString Name)
{
	Cell::_row = Row;
	Cell::_column = Column;
	Cell::_name = Name;
	Cell::Name = Name;

	return;
}

//FString Name() { return Cell::_name; }

bool Cell::IsLinked(Cell)
{
	return false;
}

void Cell::Link(Cell, bool)
{
	return;
}

void Cell::Unlink(Cell, bool)
{
	return;
}
