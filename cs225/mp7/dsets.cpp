/* Your code here! */
#include "dsets.h" 
void DisjointSets::addelements(int num)
{
	for(int i = 0; i < num ; i++)
		s.push_back(-1);
}

int DisjointSets::find(int elem)
{
	if(s[elem]<0) return elem;
	else 
	{
		s[elem] = find(s[elem]);
		return find(s[elem]);
	}
}

void DisjointSets::setunion(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	if(root1 == root2)
		return;
	int newsize = s[root1]+s[root2];

	if(s[root1]<=s[root2])
	{
		s[root2] = root1;
		s[root1] = newsize;
	}
	else if(s[root1]>s[root2])
	{
		s[root1] = root2;
		s[root2] = newsize;
	}
}