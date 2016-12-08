#include "png.h"
#include "rgbapixel.h"
int main(){
PNG A = PNG("in.png");
PNG B = PNG(A.width(),A.height());
/**
 * create two varible
 * */
for (int i = 0 ; i < A.width(); i++)
{
	for (int j = 0 ; j < A.height(); j++)
	{
	RGBAPixel Z = *A(A.width()-i-1,A.height()-j-1);
	B(i,j) -> red = Z.red;
	B(i,j) -> green = Z.green;
	B(i,j) -> blue = Z.blue;
	B(i,j) -> alpha = Z.alpha;
	}
}
	B.writeToFile("out.png");
	return 0;

}

