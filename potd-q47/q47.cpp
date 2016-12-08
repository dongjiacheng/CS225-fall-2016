#include <iostream>
using namespace std;
#define MYCHOICE "green"
#define IAMDEFINED "purple"

#ifdef IAMDEFINED
int main(){
std::cout << IAMDEFINED << " is a great color" <<std::endl;}
#endif
#ifndef IAMDEFINED
int main(){
std::cout << MYCHOICE << " is a great color" <<std::endl;}
#endif

//exclude overlap definition