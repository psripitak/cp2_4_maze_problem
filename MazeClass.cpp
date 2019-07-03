//
//*****************************************************************************
// By: Pete Sripitak
// implementation file MazeClass.cpp for class MazeClass
//*****************************************************************************

#include "MazeClass.h"
using namespace std;

MazeClass::MazeClass()
{
	row = 0;
	col = 0;
	entrance.x = 0;
	entrance.y = 0;
	exit.x = 0;
	exit.y = 0;
}	//end constructor

MazeClass::~MazeClass()
{
	//for each row, delete that row
	for (int i=0; i<row; i++)
		delete[] maze[i];
	delete[] maze;
}	//end destructor

void MazeClass::ReadMaze(ifstream& infile)
{
	char square;	//store a character from file
	infile >> row >> col;
	infile >> entrance.x >> entrance.y;
	infile >> exit.x >> exit.y;
	infile.ignore(100, '\n');
	maze = new SquareType* [row];

	//for each row of the maze
	for (int i=0; i<row; i++)
	{
		maze[i] = new SquareType[col];

		//for each column of the maze
		for (int j=0; j<col; j++)
		{
			infile.get(square);
			
			//assign square type accordingly
			switch (square)
			{
				case ' ': maze[i][j] = CLEAR; break;
				case '*': maze[i][j] = WALL; break;
			}
		}

		infile.ignore(100, '\n');
	}
}	//end ReadMaze

void MazeClass::Display() const
{
	//for each row of the maze
	for (int i=0; i<row; i++)
	{
		//for each column of the maze
		for (int j=0; j<col; j++)
		{
			//print square type accordingly
			switch (maze[i][j])
			{
				case CLEAR: cout << ' '; break;
				case WALL: cout << '*'; break;
				case PATH: cout << 'p'; break;
				case VISITED: cout << 'v'; break;
			}
		}

		cout << endl;
	}
}	//end Display

CoordinateType MazeClass::GetEntrance() const
{
	return entrance;
}	//end GetEntrance

CoordinateType MazeClass::GetExit() const
{
	return exit;
}	//end GetExit

void MazeClass::MarkVisited(CoordinateType tmpPos)
{
	maze[tmpPos.x][tmpPos.y] = VISITED;
}	//end MarkVisited

void MazeClass::MarkPath(CoordinateType tmpPos)
{
	maze[tmpPos.x][tmpPos.y] = PATH;
}	//end MarkPath

bool MazeClass::IsWall(CoordinateType tmpPos) const
{
	//if the location in the maze is wall
	if (maze[tmpPos.x][tmpPos.y] == WALL)
		return true;
	else
		return false;
}	//end IsWall

bool MazeClass::IsClear(CoordinateType tmpPos) const
{
	//if the location in the maze is clear
	if (maze[tmpPos.x][tmpPos.y] == CLEAR)
		return true;
	else
		return false;
}	//end IsClear

bool MazeClass::IsPath(CoordinateType tmpPos) const
{
	//if the location in the maze is a path being explored
	if (maze[tmpPos.x][tmpPos.y] == PATH)
		return true;
	else
		return false;
}	//end IsPath

bool MazeClass::IsVisited(CoordinateType tmpPos) const
{
	//if the location in the maze is visited
	if (maze[tmpPos.x][tmpPos.y] == VISITED)
		return true;
	else
		return false;
}	//end IsVisited

bool MazeClass::IsExit(CoordinateType tmpPos) const
{
	//if the coordinate is the same as the exit
	if (tmpPos.x == exit.x && tmpPos.y == exit.y)
		return true;
	else
		return false;
}	//end IsExit

bool MazeClass::IsInMaze(CoordinateType tmpPos) const
{
	//if the coordinate is greater or equall to 0 and less than
	//max number of row, column
	if (0 <= tmpPos.x && tmpPos.x < row &&
		0 <= tmpPos.y && tmpPos.y < col)
		return true;
	else
		return false;
}	//end IsInMaze

//end of implementation file
