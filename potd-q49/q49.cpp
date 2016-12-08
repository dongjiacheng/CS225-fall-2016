#include <iostream>
#include <vector>
#include <map>
using namespace std;

class studentTime
{
public:
	//studentTime();
	//~studentTime();
//	vector<int> time;
//	vector<string> task;
	map<double, vector<pair<int,string>>> u;
	void addTime(int uin, int time, string task){
		//if(u[uin].size == 0)
		//{
		//	vector<pair<int, string>> v;
		//	v.push_back(make_pair(time,task));
		//	u[uin] = v;
		//}
		//else{
		//	u[uin].push_back(make_pair(time,task));
		u[uin].push_back(make_pair(time,task));
}

};

int main(){
	studentTime B;
	char input = 'a';
	while (input != 'n')
	{
		cout<<"Enter UIN"<<endl;
		int uin;
		cin>>uin;
		cout<<"Enter time"<<endl;
		int time;
		cin>>time;
		cout<<"Enter task"<<endl;
		string task;
		cin >> task;
		B.addTime(uin,time,task);
		cout<<"Do you want to enter another time?";
		cin>>input;
	}


}