#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Circle: public AbstractFractal {
    private: 
        float angle = 0.0;
  public:
    Circle(string name1, int level1, int dephColor) : AbstractFractal(name1,level1, dephColor){
    };

    void draw();

    void drawFractal(float x, float y, float r, int n, int max);

};