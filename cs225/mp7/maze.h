#ifndef MAZE_H
#define MAZE_H/* Your code here! */
#include "dsets.h"
#include "png.h"
#include "rgbapixel.h"
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <map>
using std::map;
using std::vector;
using std::map;
using std::queue;
using std::stack;
class SquareMaze
{
public:
	SquareMaze();
	//~SquareMaze();
	void makeMaze(int width,int height);
	void setWall(int x,int y,int dir, bool exists);
	bool canTravel(int x, int y, int dir) const;
	PNG * drawMaze() const;
	PNG * drawMazeWithSolution();
	vector< int > solveMaze();	
private:
	 //vector<int> solveMazehelper(int i);
	 bool noMoreDFS(int i);
	 DisjointSets maze;
	 int width;
	 int height;
	 
	 struct cell
	 {
	 bool downWall;
	 bool rightWall;
	 int x;
	 int y;
	 bool visited;
	 };

	 vector<cell> cells;
};
#endif