#include "linkedlist.h"

void llUnion(LinkedList* lst1,
           LinkedList* lst2,
           LinkedList* unn)
{
	Node *A = lst1.head;
        Node *B = lst2.head;
	if(A == NULL)
        {unn.head = B;return;}
        if(B == NULL)
        {unn.head = A;return;}
        if(A->data<B->data)
          unn.head = A;
        else 
          unn.head = B;
	Node*G = unn.head;
        while(A->next != NULL && B->next!=NULL)// YOUR CODE HERE!
	{
	if(A->data<B->data)
           {G->next = A;
            A = A->next;
             G = G->next;       }
    	else (  G->next = B;
 	 	B = B->next;
		G = G->next;          )   	
	
}
	if(A->next == NULL)
         A->next =B;
        else if(B->next = NULL)
	B->next = A;
         return;
}
