#include "quadtree.h"

Quadtree::Quadtree()
{
    root = NULL;
    res = 0;
}


Quadtree::Quadtree(PNG const &source, int resolution){
    res = resolution;
    root = buildTreehelper(source, 0, 0, resolution);
}

Quadtree::QuadtreeNode* Quadtree::buildTreehelper(PNG const &source, size_t x, size_t y, int resolution){
    QuadtreeNode* subroot = new QuadtreeNode;
    if (resolution == 1){
    subroot -> element = *source(x,y);
    subroot -> nwChild = NULL;
    subroot -> neChild = NULL;
    subroot -> swChild = NULL;
    subroot -> seChild = NULL;
    return subroot;
    }
    
    int l = resolution/2;
    subroot -> nwChild = buildTreehelper(source, x, y, l);
    subroot -> neChild = buildTreehelper(source, x + l, y, l);
    subroot -> swChild = buildTreehelper(source, x, y + l, l);
    subroot -> seChild = buildTreehelper(source, x + l, y + l, l);
    //set color
    subroot->element.red = (subroot->nwChild->element.red+subroot->neChild->element.red+subroot->swChild->element.red+subroot->seChild->element.red)/4;
    subroot->element.green = (subroot->nwChild->element.green+subroot->neChild->element.green+subroot->swChild->element.green+subroot->seChild->element.green)/4;
    subroot->element.blue = (subroot->nwChild->element.blue+subroot->neChild->element.blue+subroot->swChild->element.blue+subroot->seChild->element.blue)/4;
    subroot->element.alpha = (subroot->nwChild->element.alpha+subroot->neChild->element.alpha+subroot->swChild->element.alpha+subroot->seChild->element.alpha)/4;
    return subroot;

}

Quadtree::Quadtree(Quadtree const &other){
    res = other.res;
    root = copy(other.root);
}

Quadtree::QuadtreeNode* Quadtree::copy(QuadtreeNode* othersubtree){
    if(othersubtree == NULL)
        return NULL;
    QuadtreeNode* subroot = new QuadtreeNode();
    subroot->element = othersubtree->element;
    subroot->nwChild = copy(othersubtree->nwChild);
    subroot->neChild = copy(othersubtree->neChild);
    subroot->swChild = copy(othersubtree->swChild);
    subroot->seChild = copy(othersubtree->seChild);
    return subroot;
}



Quadtree::~Quadtree ()
{
    clear();
}

void Quadtree::clear(){
    clear(root);
    root = NULL;
}

void Quadtree::clear( QuadtreeNode* &sub)
{
    if(sub == NULL)
        return;
    
    clear(sub->nwChild);
    
    clear(sub->neChild);
    
    clear(sub->swChild);
    
    clear(sub->seChild);
    
    delete sub;
    
    sub = NULL;
}




Quadtree const & Quadtree::operator= (Quadtree const &other){
    if (this != &other){
    clear();
    res = other.res;
    root = copy(other.root);
    }
    return *this;
}
 
void Quadtree::buildTree(PNG const &source, int resolution){
    clear();
    res = resolution;
    root = buildTreehelper(source, 0, 0, resolution);
}    



RGBAPixel Quadtree::getPixel(int x, int y) const{
    RGBAPixel A;
    if (x >= res || y >= res || x <0 || y < 0||root == NULL){
    
    return A;

    }
    A = getPixel(x, y, root, res);
    return A;
}

RGBAPixel Quadtree::getPixel(int x, int y, QuadtreeNode* subroot, int resolution) const{
    if (subroot -> nwChild == NULL || subroot -> neChild == NULL || subroot -> swChild == NULL || subroot -> seChild == NULL)
    return subroot -> element;


    if (x < resolution/2 && y < resolution/2)
    return getPixel(x, y, subroot -> nwChild, resolution/2);
    
    else if (x >= resolution/2 && y < resolution/2)
    return getPixel(x - resolution/2, y, subroot -> neChild, resolution/2);
    
    else if (x < resolution/2 && y >= resolution/2)
    return getPixel(x, y - resolution/2, subroot -> swChild, resolution/2);
    
    else
    return getPixel(x - resolution/2, y - resolution/2, subroot -> seChild, resolution/2);
}


PNG Quadtree::decompress()const
{
    if(root == NULL)
    {
        PNG temp;
        return temp;
    }
    PNG::PNG temp(res, res);
    int x = res-1;
    while(x>=0)
    {
        int y = res -1;
        while(y>=0)
        {
            *temp(x,y) = getPixel(x,y);
            --y;
        }
        --x;
    }
    return temp;
}


void Quadtree::clockwiseRotate (   )
{if(root == NULL)return ;
    clockwiseRotate(root);
    return;
}

void Quadtree::clockwiseRotate (QuadtreeNode* node)
{
    
    QuadtreeNode * tempNE = node->neChild;
    QuadtreeNode * tempNW = node->nwChild;
    QuadtreeNode * tempSE = node->seChild;
    QuadtreeNode * tempSW = node->swChild;
    node->neChild = tempNW;
    node->nwChild = tempSW;
    node->swChild = tempSE;
    node->seChild = tempNE;
    
    if(node->swChild != NULL)
    {
        clockwiseRotate(node->nwChild);
        clockwiseRotate(node->neChild);
        clockwiseRotate(node->swChild);
        clockwiseRotate(node->seChild);
    }
    
}

//prune
void Quadtree::prune(int tolerance){
if(root == NULL)
    return;

prune(root,tolerance);
}

void Quadtree::prune(QuadtreeNode* subroot, int tolerance){
if(subroot == NULL)
    return;
bool can = checkNode(subroot , subroot , tolerance);
if(can)
{
    clear(subroot -> nwChild);
    clear(subroot -> neChild);
    clear(subroot -> swChild);
    clear(subroot -> seChild);
    return;
}

    prune(subroot -> nwChild, tolerance);
    prune(subroot -> neChild, tolerance);
    prune(subroot -> swChild, tolerance);
    prune(subroot -> seChild, tolerance);

}

bool Quadtree::checkNode(QuadtreeNode* OR, QuadtreeNode* SubRoot, int tolerance)
{
    if(SubRoot->neChild == NULL)
        return checkdiff(OR, SubRoot,  tolerance);
    
    if(!checkNode(OR, SubRoot->nwChild, tolerance))
        return false;
    else if(!checkNode(OR, SubRoot->neChild, tolerance))
        return false;
    else if(!checkNode(OR, SubRoot->swChild, tolerance))
        return false;
    else if(!checkNode(OR, SubRoot->seChild, tolerance))
        return false;
    else
        return true;
}


bool Quadtree::checkdiff(QuadtreeNode * node, QuadtreeNode * node2, int tolerance)
{
    int red = node->element.red -  node2->element.red;
    int green = node->element.green - node2->element.green;
    int blue = node->element.blue - node2->element.blue;
    int result = red*red + blue*blue + green*green;
    if (result <= tolerance)
        return true;
    return false;
}


int Quadtree::pruneSize  ( int   tolerance ) const{
    if(root == NULL || tolerance < 0)
        return 0;
    Quadtree temp;
    temp = *this;
    temp.prune(tolerance);
    int result = count(temp.root) ;
    return result;
}

int Quadtree::count (QuadtreeNode *subroot) const{
    if(subroot->neChild == NULL)
        return 1;

    return count(subroot->neChild)+count(subroot->swChild)+count(subroot->seChild)+count(subroot->nwChild);
}
int Quadtree::idealPrune  ( int   numLeaves ) const{
    if(pruneSize(0) <= numLeaves)
        return 0;
    int ceil = ceilling(numLeaves,1);
    return findbound(ceil,ceil/2,numLeaves);
}

int Quadtree::ceilling(int numLeaves, int tolerance) const
{
    if(pruneSize(tolerance) <= numLeaves)
        return tolerance;
    return ceilling(numLeaves,tolerance * 2);
}

int Quadtree::findbound(int ceilling, int floor, int numLeaves) const{
    if(ceilling - floor <= 1){
        if(pruneSize(floor) <= numLeaves)
            return floor;
        else 
            return ceilling;
    }

    if(pruneSize((ceilling+floor)/2) <= numLeaves)
        return findbound((ceilling+floor)/2,floor,numLeaves);
    return findbound(ceilling,(ceilling+floor)/2,numLeaves);
}
