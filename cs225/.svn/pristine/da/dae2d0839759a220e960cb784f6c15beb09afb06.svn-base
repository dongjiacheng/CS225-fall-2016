#include "scene.h"
#include "rgbapixel.h"
#include"png.h"
#include<cstdint>
#include <iostream>
using namespace std;

Scene::Scene(int a)
{
this -> max = a;
scenenario  = new Image*[max];
xcord = new int[max];
ycord = new int[max];
for (int i = 0 ; i < max ; i++ )
	scenenario[i]=NULL;
}

Scene::~Scene(){
clear();
}

void Scene::clear(){
for (int i = 0 ; i < max ; i++)
	{
		if ( scenenario!= NULL)
		{	
		delete scenenario[i];
		scenenario[i] = NULL;
		}
	}
if(xcord != NULL)
{delete [] xcord;
xcord = NULL;}
if(ycord != NULL)
{delete [] ycord;
ycord = NULL;}
delete [] scenenario;

xcord = NULL;
ycord = NULL;
scenenario = NULL;

}

Scene::Scene(const Scene & source){
this->copy(source);
}

void Scene::copy( const Scene & source ){
this -> clear();
max = source.max;
scenenario = new Image*[max];
xcord = new int[max];
ycord = new int[max];
for (int i = 0; i < max; i++)
	{	
	if (source.scenenario!=NULL)
		scenenario[i] = new Image;
		*scenenario[i] = *source.scenenario[i];
		xcord[i] = source.xcord[i];
		ycord[i] = source.ycord[i];
	}
}

const Scene & Scene::operator = (const Scene &source){
	if (this != &source)
	{
	this->copy(source);
	}
	//can i juest return *this, may be wrong
	
	return *this;

	}

void Scene::changemaxlayers(int newmax){
if (newmax < max)
{
 	for (int i = (newmax - 1) ; i< max;i++)
		{
		if (scenenario[i]!=NULL)
		{	cout << "invalid newmax" << endl;
			return;
		}		
		}	
}
	Image** temp = new Image*[newmax];
	int* xcop = new int[newmax];
	int* ycop = new int[newmax];
	for (int i = 0; i < newmax; i++)
	{
	temp[i] = scenenario[i];
	xcop[i] = xcord[i];
	ycop[i] = ycord[i];		
	}
	clear();
	scenenario = temp;
	xcord = xcop;
	ycord = ycop;
	
	if(newmax > max)//necessaray or not???
	{
	for (int i = max-1 ; i<newmax ; i++)
		scenenario[i] = NULL;
	}
	max = newmax;
}


void Scene::addpicture(const char* FileName,
			int index,
			int x,
			int y
			){
	
	if(index >= max||index < 0)
	{cout << "index out of bounds"<<endl;return;}
	int i = index;
	sce  = new Image();
	sce->readFromFile(FileName);//could be wrong
	if(scenenario[i] != NULL)
	{
	delete scenenario[i];//do i have to?
	scenenario[i] = NULL;
	}
	scenenario[i] = sce;
	xcord[i]=x;
	ycord[i]=y;
}

void Scene::changelayer(int index,int newindex){
	if(index < 0||newindex<0||index>=max||newindex>=max)
	{cout<<"invalid index"<<endl;return;}
	if(index == newindex)
	return;
	if(scenenario[newindex] != NULL) delete scenenario[newindex];
	scenenario[newindex] = scenenario[index];
	scenenario[index] = NULL;
	xcord[newindex] = xcord[index];
	ycord[newindex] = ycord[index];

}

void Scene::translate(int index, int x, int y){
	if(index<0||index>=max||scenenario[index]==NULL)	
	{cout<< "invalid index"<<endl;
	return;
	}
	else 
	{
	xcord[index] = x;
	ycord[index] = y;
        }
} 

void Scene::deletepicture(int index){
	if(index<0||index>=max||scenenario[index]==NULL)
	 {cout<< "invalid index"<<endl;
        return;
        }
	else 
	{	delete scenenario[index];
		scenenario[index] = NULL;
	}		

}

Image* Scene::getpicture(int index) const{
	if(index<0||index>=max||scenenario[index]==NULL)
         {cout<< "invalid index"<<endl;
        return NULL;
        }
	return scenenario[index];
	}
Image Scene::drawscene()const{
size_t ndwidth = 0;
size_t ndheight = 0;
for (int i = 0;i<max;i++)
{
	if(scenenario[i]!=NULL)
	{
	size_t tswidth = scenenario[i]->width()+(size_t)xcord[i];
	size_t tsheight = scenenario[i]->height()+(size_t)ycord[i];
	if(tswidth>ndwidth)
	ndwidth = tswidth;
	if(tsheight>ndheight)
	ndheight = tsheight;
	
	}}	
		
Image output = Image();
output.resize(ndwidth,ndheight);
for (int i = 0; i < max ; i++){
	if(scenenario[i] != NULL)
	{
	for(size_t a = 0; a < scenenario[i]->width();a++)
	{
	for(size_t b = 0;b < scenenario[i]->height();b++)
	{
	*output(a+(size_t)xcord[i],b+(size_t)ycord[i])=*(*scenenario[i])(a,b) ;
	}

	}


}

}	
return output;

}
