#include "image.h"
#include <cstdint>
#include "rgbapixel.h"

using namespace std;

void Image::flipleft()
{
//check whether need to create image?
int  width = this->width();
int  height = this->height();
RGBAPixel  copy;
for (int i = 0;i<(width/2) ; i++)

	{
	for ( int j = 0; j<height; j++)
	{
	copy = *(*this)(i,j);//necessary to use of this?
	*(*this)(i,j) = *(*this)(width-i-1,j);
	*(*this)(width-i-1,j) = copy;
	}
	}	
this->writeToFile("out.png");
}

void Image::adjustbrightness(int r, int g, int b){
int width =this-> width();
int height =this-> height();
for (int i = 0;i<width;i++)
{
	for (int j = 0; j<height; j++)
	{
	int R = 0;
	if( r + (*this)(i,j)->red > 255)
	R = 1;
	else if( r + (*this)(i,j)->red < 0)
	R = 2;
	switch(R)
	{
	case 1:
	(*this)(i,j)->red = 255;
	break;
	case 2:
	(*this)(i,j)->red = 0;
	break;
	default: (*this)(i,j)->red += r;
	}
	int G = 0 ;
        if ( g + (*this)(i,j)->green > 255)
	G = 1;
	else if(g + (*this)(i,j)->green < 0)
	G = 2;
       
        switch(G)
        {
        case 1:
        (*this)(i,j)->green = 255;
        break;
        case 2:
        (*this)(i,j)->green = 0;
        break;
        default: (*this)(i,j)->green += g;
        }
	int B = 0;
	if( b + (*this)(i,j)->blue > 255)
	B = 1;
	else if (b + (*this)(i,j)->blue < 0)
	B = 2;
        switch(B)
        {
        case 1:
        (*this)(i,j)->blue = 255;
        break;
        case 2:
        (*this)(i,j)->blue = 0;
        break;
        default: (*this)(i,j)->blue += b;
        }
	}
}
}

void Image::invertcolors(){
int width =this-> width();
int height =this-> height();
for (int i = 0;i<width;i++)
{
        for (int j = 0; j<height; j++)
        {
        uint8_t x = (*this)(i,j)->red;
	uint8_t y = (*this)(i,j)->green;
	uint8_t z = (*this)(i,j)->blue;
	(*this)(i,j)->red = 255-x;
	(*this)(i,j)->green = 255-y;
	(*this)(i,j)->blue = 255-z;
        }
}

}
