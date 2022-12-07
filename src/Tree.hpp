#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Tree: public AbstractFractal {
    private: 
        float r = 0.0;
        float length1 = 0.0;
  public:
    Tree(string name1, float x1, float y1, int level1, int dephColor, float rad, float length) : AbstractFractal(name1, x1, y1, level1, dephColor){
        this->r = rad;
        this->length1 = length;
    };

    void draw();

    void drawFractal(float x, float y, float rad, int n, int max, float length);

    float getX(){return this->x;}
    float getY(){return this->y;}

    int getLevel(){return this->level;}

    float getLength(){return length1;}
    string getName(){return this->name;}

};










