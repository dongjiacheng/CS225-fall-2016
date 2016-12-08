#include "common.h"
#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

void updateMax(Node<int> *&root)
{
	// YOUR CODE HERE!
	if(root == NULL)
	return;
	updateMax(root->left);
	updateMax(root->right);
	if(root->left == NULL && root -> right == NULL)
	return;
	else if(root->left == NULL)
	 root->data += root->right->data;
	
	else if(root->right == NULL)
	root ->data += root ->left->data;
	else if(root->left->data > root->right->data)
		root->data += root->left->data;
	else
		root->data += root->right->data;
}
