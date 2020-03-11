/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
#include "list.h"
#include <iostream>
#include "string"
#include <cmath>
template <class T>
List<T>::~List()
{
 clear();   /// @todo Graded in MP3.1
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
for(i = 0; i< length; i++)
{
ListNode* temp = head->next;
delete head;
head = temp;


}
length = 0;
tail = NULL;
length = 0;
}    /// @todo Graded in MP3.1


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
    /// @todo Graded in MP3.1
ListNode *temp = new ListNode(ndata);
if(length != 0)
{  head->prev = temp;
  temp->prev = NULL;
  temp->next = head;
  head = temp; /// @todo Graded in MP3.1
  length++;}

else{

 head = temp;
 tail = temp;
 temp-> prev = NULL;
 temp-> next = NULL;
 length ++;
}
}


/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
ListNode *temp = new ListNode(ndata);
if(length != 0){
  tail->next = temp;
  temp->next = NULL; 
  temp->prev = tail;
  tail = temp; /// @todo Graded in MP3.1
  length++;
}
else{

 head = temp;
 tail = temp;
 temp-> prev = NULL;
 temp-> next = NULL;
 length ++;
}
}
/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
  reverse(head, tail);          //call the help function
  ListNode * temp = head;       //reset head and tail
  head = tail;
  tail = temp;
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse( ListNode * & startPoint, ListNode * & endPoint )
{
  if (head==NULL)
    return; 
  ListNode* node = new ListNode;
  node -> next = NULL;
  node -> prev = NULL;
  if (startPoint -> next != NULL)           //check null 
  {
    reverse(startPoint -> next,endPoint);       //reverse next
    node -> next = startPoint -> next;        
    node -> prev = startPoint -> prev;
    startPoint -> prev = node -> next;
    startPoint -> next = node -> prev;
  }
  else 
  {
    node -> next = startPoint -> next;
    node -> prev = startPoint -> prev;
    startPoint -> prev = node -> next;
    startPoint -> next = node -> prev;
  }
  delete node;
  /// @todo Graded in MP3.1
}
/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth( int n )
{ 
  if (head==NULL)
    return; 
  ListNode* node = new ListNode;
  node -> next = NULL;
  node -> prev = NULL;  
  ListNode* startn = head;
  ListNode* endn = head;
  int i = 1;                //count for nth
  int ch = 0;               //check for head
  while (endn -> next != NULL)            //check null and make a loop
  {
    while ((i < n) && (endn -> next != NULL))     //check null and make a nth reverse
    {
      i++;    
      endn = endn -> next;
    }
    i = 1;
    node -> next = endn -> next;
    node -> prev = startn -> prev;
    endn -> next = NULL;
    startn -> prev = NULL;    
    reverse(startn, endn);
    startn -> next = node -> next;
    endn -> prev = node -> prev;  
    if (node -> next != NULL)
      node -> next -> prev = startn;
    if (node -> prev != NULL)
      node -> prev -> next = endn;
    if (ch == 0)
    {
      head = endn;            //set head
      ch++; 
    }   
    if (startn -> next != NULL)         //the startpoint of next nth reverse
    {
      startn = startn -> next;
    }
    endn = startn;
  }
  tail = endn;                //set tail 
  delete node;
  /// @todo Graded in MP3.1

}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
if(length <= 1)
return;
int A = 0;
ListNode *temphead;
temphead = head;
ListNode *temp;
ListNode *O;
while(temphead -> next != NULL && temphead->next->next!= NULL){

O = temphead;
temp = temphead->next;
temphead = temphead->next->next;
temphead->prev = O;
O->next = temphead;
temp->prev = tail;
tail->next = temp;
tail = temp;
temp->next = NULL;
}
   /// @todo Graded in MP3.1
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
  if(start == NULL)
   return start;
  if(splitPoint == 0)
   return NULL;
  ListNode* temp = start;

  if(length <= 1 )
    return start ;
  if(splitPoint>length)
     return start;
  if(splitPoint<0)
     return start;  
 
 int i = splitPoint; 
 while(temp!= NULL&&splitPoint > 0 )
   {
    splitPoint --;
    temp = temp->next;
  }
  if(temp!=NULL)
 { ListNode * tp = temp->prev; /// @todo Graded in MP3.2
  tp->next = NULL;
  tail = tp;
  temp->prev = NULL;}
   return temp;
   // change me!
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
	
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{

/**
//Basecase
if(first == NULL)
{cout<<"end"<<endl;
return second;}
if(second == NULL)
{cout<<"tail with first"<<endl;
return first;}
cout<<"timesruning ";
ListNode* temp;
ListNode* newhead;

if(first->data < second->data)   
{
cout<<"firstsmall"<<endl;
temp = merge(first->next,second);
cout<<"??";
//if(temp == NULL)
//return NULL;
temp->prev = first;
cout<<"temp problem";
first->next = temp;
newhead = first;
}
else
{
cout<<"secondsmall"<<endl;
temp = merge(first,second->next);
cout<<"find problem";
//if(temp == NULL)
//return NULL;
temp->prev = second;
cout<<"mayhere";
second->next = temp;
cout<<"orhere";
newhead = second;
}

return newhead;
}

*/
    if(first == NULL)
     return second;
    if(second == NULL)
     return first;
    

     ListNode * temp1 = first;
     ListNode * temp2 = second;
     ListNode * c;
     ListNode * a;
     ListNode * newhead = temp1;
    while(temp1 != NULL && temp2 != NULL)
       {  while(temp1->data < temp2->data && temp1->next!= NULL)
             temp1 = temp1->next;
          if(temp1->next == NULL)
            {
		if(temp1->data < temp2 ->data)
		{
                 temp1->next = temp2;
		 temp2->prev = temp1;
		  return newhead; }
		else{
		 c = temp2;
		 temp2 = temp2->next;
		 c->next = temp1;
		 c->prev = temp1->prev;
		//what if temp1->prev is NULL;
		 if(temp1->prev!=NULL)
                   temp1->prev->next = c;
		else newhead = c;//having our new head here
		temp1->prev = c; 
                   
                        }


		}
         else if(temp1->prev != NULL)
              {
 		c = temp1->prev;	
	        c -> next = temp2;
                ListNode *b = temp2;
		temp2 = temp2->next;
                b -> next = temp1;
                temp1->prev = b;
		b->prev = c;
              }
          else
              {  a = temp2;
                 temp2 = temp2->next ;
  		 a->next = temp1;
                 temp1 -> prev = a;
		 newhead = a;                  
			}
           // temp1 = temp1->next;
	} 
//have to put the two which next is null
    
       
                 /// @todo Graded in MP3.2
    return newhead; // change me!
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{
if(start == NULL||chainLength <= 0)
return NULL;
if(chainLength==1)
return start;
int newlength = chainLength/2; 
ListNode *temp = split(start,newlength);
ListNode*A = mergesort(start,newlength);
ListNode*B = mergesort(temp,chainLength-newlength);
ListNode*result = merge(A,B);

 // @todo Graded in MP3.2
    return result; // change me!
}
