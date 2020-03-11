#include "common.h"
#include "quadtree.h"

#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

int Quadtree::tallyNeighbors(RGBAPixel const & target, 
    QuadtreeNode const * curNode, int tolerance) const {
	if(curNode -> nwChild == NULL)
	{
	if(maxDev(target,curNode)<= tolerance)
	return 1;
	else 
	return 0;
	}    //YOUR CODE HERE
	else {
	return tallyNeighbors(target,curNode->nwChild,tolerance) + tallyNeighbors(target,curNode->neChild,tolerance)+ tallyNeighbors(target,curNode->seChild,tolerance)+tallyNeighbors(target,curNode->swChild,tolerance);    
}
}

void Quadtree::prunish(int tolerance, double percent) {
if(root == NULL)
	return; 
prunish(root,tolerance,resolution ,percent);   //YOUR CODE HERE
} 

void Quadtree::prunish(QuadtreeNode * curNode, int tolerance, int res, double percent) {
 double number = tallyNeighbors(curNode->element,curNode,tolerance )/ (res* res); 
	if(number >= percent)
	{
	clear(curNode->nwChild);
	clear(curNode->neChild);
	clear(curNode->seChild);
	clear(curNode->swChild);
	}  //YOUR CODE HERE
	else
	{
	prunish(curNode->nwChild,tolerance,res/2,percent);
	prunish(curNode->neChild,tolerance,res/2,percent);
	prunish(curNode->swChild,tolerance,res/2,percent);
	prunish(curNode->seChild,tolerance,res/2,percent);	
	}	
}
