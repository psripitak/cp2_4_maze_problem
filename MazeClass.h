//
//*****************************************************************************
// By: Pete Sripitak
// header file MazeClass.h for class MazeClass
//*****************************************************************************

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

#ifndef MAZECLASS_H
#define MAZECLASS_H

enum SquareType{CLEAR, WALL, PATH, VISITED};

struct CoordinateType
{
	int x;
	int y;
};

class MazeClass
{
public:
	//description:		default constructor
	//precondition:		none
	//postcondition:	data are set to 0
	MazeClass();

	//description:		default destructor
	//precondition:		none
	//postcondition:	maze is deleted
	~MazeClass();

	//description:		read a maze from a file
	//precondition:		file is opened
	//postcondition:	store number of row and column
	//					store entrance and exit location
	//					maze is created
	void ReadMaze(ifstream& infile);

	//description:		display the maze
	//precondition:		maze is created
	//postcondition:	maze is displayed
	void Display() const;

	//description:		return the location of the entrance
	//precondition:		none
	//postcondition:	return entrance
	CoordinateType GetEntrance() const;

	//description:		return the location of the exit
	//precondition:		none
	//postcondition:	return exit
	CoordinateType GetExit() const;

	//description:		mark one maze location being visited
	//precondition:		none
	//postcondition:	current location = visited
	void MarkVisited(CoordinateType tmpPos);

	//description:		mark one maze location as part of the path
	//					being explored by the creature
	//precondition:		none
	//postcondition:	current location = path
	void MarkPath(CoordinateType tmpPos);

	//description:		determine whether a particular location
	//					in the maze is wall
	//precondition:		none
	//postcondition:	return true or false
	bool IsWall(CoordinateType tmpPos) const;

	//description:		determine whether a particular location
	//					in the maze is clear
	//precondition:		none
	//postcondition:	return true or false
	bool IsClear(CoordinateType tmpPos) const;

	//description:		determine whether a particular location
	//					is part of the path being explored
	//precondition:		none
	//postcondition:	return true or false
	bool IsPath(CoordinateType tmpPos) const;

	//description:		determine whether a particular location
	//					has been visited and does not lead to exit
	//precondition:		none
	//postcondition:	return true or false
	bool IsVisited(CoordinateType tmpPos) const;

	//description:		determine whether a particular location
	//					in the maze is the exit point
	//precondition:		none
	//postcondition:	return true or false
	bool IsExit(CoordinateType tmpPos) const;

	//description:		determine whether a particular location
	//					provided is part of the maze
	//precondition:		none
	//postcondition:	return true or false
	bool IsInMaze(CoordinateType tmpPos) const;

private:
	SquareType** maze;			//2D array pointer of maze
	int row;					//number of row
	int col;					//number of column
	CoordinateType entrance;	//coordinate of entrance
	CoordinateType exit;		//coordinate of exit
};	//end class

#endif
//end of header file
