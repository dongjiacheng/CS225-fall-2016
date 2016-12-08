#include "common.h"
#include <iostream>
#include <queue>

/*
  As a reminder, useful STL queue methods include:
  empty : Test whether container is empty (public member function)
  size : Return size (public member function)
  front : Access next element (public member function)
  push : Insert element (public member function)
  pop : Remove next element (public member function)
*/

using namespace std;

int get(queue<int> &q, int pos)
{
if(q.empty())
return -1;
if(pos > (q.size()-1) || pos < 0)
        return -1;
if(pos == 0)
return q.front();
//int A = q.front();
int B;
queue<int>a;
while(!q.empty())
{
a.push(q.front());
q.pop();
pos--;
if(pos == 0)
B = q.front();
}
q = a;

return B;
}
	// YOUR CODE HERE!


