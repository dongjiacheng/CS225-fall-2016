#include "common.h"
#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

int height(Node<int> *subroot)
{

	if(subroot == NULL )
	return -1;
	return 1 + max(height(subroot->left),height(subroot->right));

}

bool isBalanced(Node<int> *&root)
{
	if(root == NULL)
	return true;
	int l = height(root->left);
	int r = height(root -> right);

	if(isBalanced(root->left)&&isBalanced(root->right)&& abs(l-r)<= 1)
	return true;	// YOUR CODE HERE!
	return false;
}
