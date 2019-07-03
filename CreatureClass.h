//
//*****************************************************************************
// By: Pete Sripitak
// header file CreatureClass.h for class CreatureClass
//*****************************************************************************

#include "MazeClass.h"
using namespace std;

#ifndef CREATURECLASS_H
#define CREATURECLASS_H

class CreatureClass
{
public:
	//description:		default constructor
	//precondition:		none
	//postcondition:	data are set to 0
	CreatureClass();

	//description:		move left one step
	//precondition:		none
	//postcondition:	y - 1
	void MoveLeft();

	//description:		move right one step
	//precondition:		none
	//postcondition:	y + 1
	void MoveRight();

	//description:		move up one step
	//precondition:		none
	//postcondition:	x - 1
	void MoveUp();

	//description:		move down one step
	//precondition:		none
	//postcondition:	x + 1
	void MoveDown();

	//description:		assign creature to a location
	//precondition:		none
	//postcondition:	creature's coordinate = coordinate passed
	void AssignLocation(CoordinateType tmpPos);

	//description:		report its current location
	//precondition:		none
	//postcondition:	return creature location
	CoordinateType ReportLocation() const;

private:
	CoordinateType creature;	//the current location of the creature
};	//end class

#endif
//end of header file
