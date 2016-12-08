#ifndef PATIENT_H
#define PATIENT_H
#include <string>
//using namespace std;
class Patient
{
public:
	Patient();
	~Patient();
private:
	int rank;
	std::string name;
};
int main()
{
	return 0;
}

#endif