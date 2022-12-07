#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Circle: public AbstractFractal {
    private: 
        float r = 0.0;
  public:
    Circle(string name1, float x1, float y1, int level1, int dephColor, float rad) : AbstractFractal(name1, x1, y1, level1, dephColor){
        this->r = rad;
    };

    void draw();

    void drawFractal(float x, float y, float r, int n, int max);

    float getX(){return this->x;}
    float getY(){return this->y;}

    int getLevel(){return this->level;}
    string getName(){return this->name;}

};