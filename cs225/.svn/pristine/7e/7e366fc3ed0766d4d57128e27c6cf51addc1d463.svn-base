/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
   
  //  cout<<curDim<<endl;
    if(curDim > Dim || curDim < 0)
        return false;
    if(first[curDim]!=second[curDim])
    {
       //  cout<<"passhere"<<endl;
    return first[curDim]<second[curDim];
    }
    //cout<<"itisthesame"<<endl;
    return first < second;//what if k is biigger than dimension
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int d1 = 0;
    int d2 = 0;
    for(int i = 0; i < Dim; i++)
    {
       d2 += (target[i]-currentBest[i])*(target[i]-currentBest[i]);
       d1 += (target[i]-potential[i])*(target[i]-potential[i]);
    }
    if(d1 == d2)
        return potential<currentBest;
    return d1 < d2;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
   // cout<<"checkConstruct"<<endl;
    points = newPoints;
    if(!points.empty())
    KDTreehelper(0,points.size()-1, 0);
}

template <int Dim>
void KDTree<Dim>::KDTreehelper(int start, int end, int d)
{
if(start >= end)
    return;
//cout<<"check"<<endl;
sort(start,end,d);
int mid = (start + end)/2;
//sort(start,end,d);
int d2 = (d+1)%Dim;
KDTreehelper(start,mid-1,d2);
KDTreehelper(mid+1,end,d2);

}


template <int Dim>
void KDTree<Dim>::swap(int a, int b)
{
Point<Dim> temp = points[a];
points[a] = points[b];
points[b] = temp;
}

template <int Dim>
void KDTree<Dim>::sort(int start, int end, int d)
{
    
    if(start >= end)
        return;
   // cout<<"end"<<endl;
   // cout<<d<<endl;
for(int a = start; a <= end; a++){//if start ==end?
    for (int b = a; b <= end; b++)
    {
       // cout<<a<<' '<<b<<endl;
        if(smallerDimVal(points[b],points[a],d))
            swap(a,b);
       // cout<<b<<endl;
    }
}

}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    int mid = (points.size()-1)/2;
    return findNearestNeighborhelper(query, 0, points.size()-1 , 0, points[mid], true,true);
}
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighborhelper(const Point<Dim>& query, int start, int end, int d,Point<Dim> curr, bool left, bool havenotbeen) const
{

    if(start>end)
        return curr;
    int mid = (start+end)/2;
    Point<Dim> currentBest = curr;
    int d2 = (d+1)%Dim;
    
    
    if(smallerDimVal(points[mid],query,d))
       { currentBest = findNearestNeighborhelper(query,mid+1,end,d2,points[mid],true,true); left = false;}
    else
        currentBest = findNearestNeighborhelper(query,start,mid-1,d2,points[mid],true,true);
    
    
    if(currentBest != curr)//may cause trouble : warnning
      //  return currentBest;    
    {
    if(shouldReplace(query,currentBest,curr))
        currentBest = curr;
    }
    //replace with ideal one



    int radiussquare = radius(query,currentBest);
    int distancetoplane =  distance(points[mid],query,d);
    Point<Dim> temp;
    if(radiussquare >= distancetoplane && havenotbeen)
    {   
        havenotbeen = false;
        if(left)
            temp = findNearestNeighborhelper(query,mid+1,end,d2,points[mid],true,true);
        else
            temp = findNearestNeighborhelper(query,start,mid-1,d2,points[mid],true,true);   
    //go another side



    if(shouldReplace(query,currentBest,temp))
        currentBest = temp;
    }   
    return currentBest;
}

template <int Dim>
int KDTree<Dim>::radius(const Point<Dim> target,Point<Dim> currentBest) const
{
    int d2 = 0;
    for(int i = 0; i < Dim; i++)
    {
       d2 += (target[i]-currentBest[i])*(target[i]-currentBest[i]);
    }
    return d2;
}

template <int Dim>
int KDTree<Dim>::distance(Point<Dim> child,Point<Dim> parent, int d) const
{
return (child[d] - parent[d])*(child[d] - parent[d]);

}

