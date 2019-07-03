//
//*****************************************************************************
// By: Pete Sripitak
// implementation file CreatureClass.cpp for class CreatureClass
//*****************************************************************************

#include "CreatureClass.h"
using namespace std;

CreatureClass::CreatureClass()
{
	creature.x = 0;
	creature.y = 0;
}	//end constructor

void CreatureClass::MoveLeft()
{
	creature.y--;
}	//end MoveLeft

void CreatureClass::MoveRight()
{
	creature.y++;
}	//end MoveRight

void CreatureClass::MoveUp()
{
	creature.x--;
}	//end MoveUp

void CreatureClass::MoveDown()
{
	creature.x++;
}	//end MoveDown

void CreatureClass::AssignLocation(CoordinateType tmpPos)
{
	creature.x = tmpPos.x;
	creature.y = tmpPos.y;
}	//end AssignLocation

CoordinateType CreatureClass::ReportLocation() const
{
	return creature;
}	//end ReportLocation

//end of implementation file
