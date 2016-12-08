#include <iostream>
using namespace std;
class Circle
{
public:
	Circle();
	~ Circle();
	double getR() const {return radius;};
	void setradius(double a) {radius = a;};
private:
	double radius;

};

void print(const Circle &C){cout<<"I am a circle. My radius is "<<C.getR()<<endl;} 
//void setradius(const Circle &C,double a){C.setradius(a);}8.cpp:16:42: error: member function 'setradius' not viable: 'this' argument
  //    has type 'const Circle', but function is not marked const
int main(){
 	Circle A;
 	A.setradius(3);
 	Circle const *B =  &A;
 	const Circle *C = &A;
 	print(*B);
 	print(*C);
 	

}
