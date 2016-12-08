#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

map<int, vector<pair<int, string> > > records;

struct printTime
{
    //printTime(vector<pair<int,string>> x):x(x){};
    void operator()(vector<pair<int,string>> x){
        int i = 1;
        for(auto & a : x)
        {
            cout<< i <<"- " <<a.first<<" minutes:  "<<a.second<<endl;
            i++;
        }
    }
//private:
  //  vector<pair<int,string>> x;
};

void printRecord(int uin){
    cout<<uin<<endl;
    printTime print;
    print(records[uin]);
}

void printAll(){

    for(auto & itr : records)
    {
        printRecord(itr.first);
    }

}

void addTime(int uin, int time, string task){
    map<int, vector<pair<int, string> > >::iterator it;
    it = records.find(uin);
    if(it == records.end()){            // see if uin is in map already
        vector<pair<int, string> > vec;
        pair<int, string> entry (time, task);
        vec.push_back(entry);
        records.insert(pair<int, vector<pair<int, string> > > (uin, vec));
    }
    else{
        pair<int, string> entry (time, task);
        records[uin].push_back(entry);
    }
}

int main(){
    char input;
    do{
        int uin, time;
        string task;
        cout << "Enter a UIN: ";
        cin >> uin;
        cin.ignore();       // cin leaves the /n character, remove it from the buffer
        cout << "Enter the amount of time worked (rounded to the nearest minute): ";
        cin >> time;
        cin.ignore();       // remove newline from buffer
        cout << "Enter a description of the task(s) performed: ";
        getline(cin, task);
        addTime(uin, time, task);
        cout << "Would you like to create another time entry (y/n): ";
        cin >> input;
    } while(input == 'y');
    return 0;
}
