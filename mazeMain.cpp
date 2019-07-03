//
//*****************************************************************************
////Programmer:		Pete Sripitak

//Description:		This program solves the maze problem using recursion plus
//					backtracking.

//Input:			File name

//Output:			1.	SquareType** maze: Show the solved Maze.
//*****************************************************************************

#include "MazeClass.h"
#include "CreatureClass.h"
using namespace std;

//function prototypes
void GoNorth(MazeClass& maze, CreatureClass& creature, bool& success);
void GoSouth(MazeClass& maze, CreatureClass& creature, bool& success);
void GoEast(MazeClass& maze, CreatureClass& creature, bool& success);
void GoWest(MazeClass& maze, CreatureClass& creature, bool& success);

int main()
{
	//variable declarations
	MazeClass maze;				//MazeClass object for the maze
	CreatureClass creature;		//CreatureClass object for the creature
	string filename;			//store file name
	ifstream infile;			//input file stream
	bool success = false;		//store flag

	filename = "MyMaze1.dat";
	infile.open(filename);
	assert(infile);
	maze.ReadMaze(infile);

	cout << endl << "Original Maze" << endl;
	maze.Display();
	cout << endl;

	creature.AssignLocation(maze.GetEntrance());
	maze.MarkPath(maze.GetEntrance());

	//while success is not true
	while (!success)
	{
		GoNorth(maze, creature, success);
		GoWest(maze, creature, success);
		GoSouth(maze, creature, success);
		GoEast(maze, creature, success);
		break;
	}

	//if success is true
	if (success)
	{
		cout << "A solution was found! Follow the \"p\"!" << endl;
		cout << "Final Maze" << endl;
		maze.Display();
		cout << endl;
	}
	else
	{
		cout << "No solution was found!" << endl;
		cout << "Final Maze" << endl;
		maze.Display();
		cout << endl;
	}

	infile.close();
	return 0;
}	//end main

//function GoNorth to examine all the paths that start
//at the square to the North of the present square
void GoNorth(MazeClass& maze, CreatureClass& creature, bool& success)
{
	CoordinateType tmpPos = creature.ReportLocation();	//temp coordinate
	tmpPos.x--;

	//if square is inside the maze, is clear, and has not been visited
	if (maze.IsInMaze(tmpPos) && maze.IsClear(tmpPos) && !maze.IsVisited(tmpPos))
	{
		creature.MoveUp();
		tmpPos = creature.ReportLocation();
		maze.MarkPath(tmpPos);
		
		//if square is the exit
		if (maze.IsExit(tmpPos))
			success = true;
		else
		{
			GoNorth(maze, creature, success);

			//if success is not true
			if (!success)
			{
				GoWest(maze, creature, success);

				//if success is not true
				if (!success)
				{
					GoEast(maze, creature, success);

					//if success is not true
					if (!success)
					{
						maze.MarkVisited(tmpPos);
						creature.MoveDown();
						tmpPos = creature.ReportLocation();
					}
				}
			}
		}
	}
}	//end GoNoth

//function GoSouth to examine all the paths that start
//at the square to the South of the present square
void GoSouth(MazeClass& maze, CreatureClass& creature, bool& success)
{
	CoordinateType tmpPos = creature.ReportLocation();	//temp coordinate
	tmpPos.x++;

	//if square is inside the maze, is clear, and has not been visited
	if (maze.IsInMaze(tmpPos) && maze.IsClear(tmpPos) && !maze.IsVisited(tmpPos))
	{
		creature.MoveDown();
		tmpPos = creature.ReportLocation();
		maze.MarkPath(tmpPos);
		
		//if square is the exit
		if (maze.IsExit(tmpPos))
			success = true;
		else
		{
			GoSouth(maze, creature, success);

			//if success is not true
			if (!success)
			{
				GoWest(maze, creature, success);

				//if success is not true
				if (!success)
				{
					GoEast(maze, creature, success);

					//if success is not true
					if (!success)
					{
						maze.MarkVisited(tmpPos);
						creature.MoveUp();
						tmpPos = creature.ReportLocation();
					}
				}
			}
		}
	}
}	//end GoSouth

//function GoEast to examine all the paths that start
//at the square to the East of the present square
void GoEast(MazeClass& maze, CreatureClass& creature, bool& success)
{
	CoordinateType tmpPos = creature.ReportLocation();	//temp coordinate
	tmpPos.y++;

	//if square is inside the maze, is clear, and has not been visited
	if (maze.IsInMaze(tmpPos) && maze.IsClear(tmpPos) && !maze.IsVisited(tmpPos))
	{
		creature.MoveRight();
		tmpPos = creature.ReportLocation();
		maze.MarkPath(tmpPos);
		
		//if square is the exit
		if (maze.IsExit(tmpPos))
			success = true;
		else
		{
			GoEast(maze, creature, success);

			//if success is not true
			if (!success)
			{
				GoNorth(maze, creature, success);

				//if success is not true
				if (!success)
				{
					GoSouth(maze, creature, success);

					//if success is not true
					if (!success)
					{
						maze.MarkVisited(tmpPos);
						creature.MoveLeft();
						tmpPos = creature.ReportLocation();
					}
				}
			}
		}
	}
}	//end GoEast

//function GoWest to examine all the paths that start
//at the square to the West of the present square
void GoWest(MazeClass& maze, CreatureClass& creature, bool& success)
{
	CoordinateType tmpPos = creature.ReportLocation();	//temp coordinate
	tmpPos.y--;

	//if square is inside the maze, is clear, and has not been visited
	if (maze.IsInMaze(tmpPos) && maze.IsClear(tmpPos) && !maze.IsVisited(tmpPos))
	{
		creature.MoveLeft();
		tmpPos = creature.ReportLocation();
		maze.MarkPath(tmpPos);
		
		//if square is the exit
		if (maze.IsExit(tmpPos))
			success = true;
		else
		{
			GoWest(maze, creature, success);

			//if success is not true
			if (!success)
			{
				GoNorth(maze, creature, success);

				//if success is not true
				if (!success)
				{
					GoSouth(maze, creature, success);

					//if success is not true
					if (!success)
					{
						maze.MarkVisited(tmpPos);
						creature.MoveRight();
						tmpPos = creature.ReportLocation();
					}
				}
			}
		}
	}
}	//end GoWest

//end of client file
