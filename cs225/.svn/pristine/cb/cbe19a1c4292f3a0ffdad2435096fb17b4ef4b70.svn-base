#ifndef SCENE_H
#define SCENE_H
#include "image.h"

class Scene {
public :
Scene(int max);
Scene(const Scene &source);
~Scene();
const Scene & operator=( const Scene &source);
void changemaxlayers(int newmax);
void addpicture(const char *FileName, int index,int x, int y);
void changelayer(int index, int newindex);
void translate(int index, int xcoord,int ycoord);
void deletepicture (int index);
Image* getpicture(int index) const;
Image drawscene()const;
void clear();
void copy(const Scene & source);
private:
int max;//one of the attribution of scene
int *xcord;
int *ycord;//x and y coordinates
Image *sce;
Image **scenenario;
};

#endif
