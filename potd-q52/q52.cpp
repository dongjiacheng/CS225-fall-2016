#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>
#include <vector>
class Hospital
{
public:
	Hospital();
	~Hospital();
	void print_patients(){std::cout<<"patients"<<std::endl;}
	void elapse_hour(std::vector <std::string>new_patients);
	
};
int main(){return 0;}
#endif