/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"


using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * @todo Implement this function!
     */
	int Rows = theSource.getRows();
	int Columns = theSource.getColumns();
	MosaicCanvas* Result = new MosaicCanvas(Rows,Columns);

	
	map<RGBAPixel,TileImage> hashtable;
	vector<Point<3>> v;
	
	for(auto &Implement:theTiles)
	{
		hashtable[Implement.getAverageColor()] = Implement;
		RGBAPixel temp = Implement.getAverageColor();
		double Array[3] = {(double)temp.red,(double)temp.green,(double)temp.blue};
		Point<3> points(Array);
		v.push_back(points);
	}

	KDTree<3> Tree(v);

	for(int i = 0; i < Rows; ++i)
		for(int j = 0; j<Columns; ++j)
		{
			RGBAPixel origin = theSource.getRegionColor(i,j);
			double Arr[3] = {(double)origin.red,(double)origin.green,(double)origin.blue};
			Point<3> objectpoint(Arr);
			Point<3> rvalue = Tree.findNearestNeighbor(objectpoint);			
			RGBAPixel search = RGBAPixel(rvalue[0],rvalue[1],rvalue[2]);
			TileImage output = hashtable[search];
			Result->setTile(i,j,output);
		}
	return Result;
    //return NULL;
}

