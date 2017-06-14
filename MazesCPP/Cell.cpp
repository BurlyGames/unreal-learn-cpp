/*
The individual Cell object implementation
*/

#include "Cell.h"
#include <vector>

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

	Links.reserve(4);


	return;
}

//FString Name() { return Cell::_name; }

bool Cell::IsLinked(Cell* cell)
{
	// Check through the local Links collection to see if the passed Cell is present

	std::vector<Cell*>::iterator it = std::find(Links.begin(), Links.end(), cell);

	// Cell was found before end
	return (it != Links.end());
}

void Cell::Link(Cell* cell)
{
	Links.push_back(cell);

	//Cell::Links.insert(Cell::Links.begin(), *cell);
	//cell->Link(this);
	//Links.push_back(*cell);


	//// Add the passed Cell into the local Links collection
	//std::vector<Cell>::iterator localIterator = Cell::Links.begin();
	//Cell::Links.insert(localIterator, *cell);

	//// From the target Cell, link back to this one
	//cell->Link(this);

	return;
}

void Cell::Unlink(Cell* cell)
{
	return;
}
