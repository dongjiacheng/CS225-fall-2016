#include "linkedlist.h"
#include <iostream>
using namespace std;

bool removeAt(LinkedList &mylist, int pos)
{
  Node *A ;
  int h = pos;
  A = mylist.head;
  if(A == NULL)
	  return 0;
  if(pos<=0)
   return 0;
  if(pos == 1)
   {
  mylist.head = A->next;
   delete A;
   return 1;
   } 
   
   for(int i = 0; i < (h - 2);i++)
       {
        if(A->next == NULL)
		return 0;
        A = A->next;

	}
  Node *temp = A;
   A = A->next;
   temp->next = A->next;
   delete A;
   A = NULL;

    // YOUR CODE HERE!
	return 1;
}
