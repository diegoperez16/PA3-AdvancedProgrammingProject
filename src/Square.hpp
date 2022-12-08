#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Square: public AbstractFractal {
    private: 
  public:
    Square(string name1,  int level1, int dephColor) : AbstractFractal(name1,level1, dephColor){
    };

    void draw();

    void drawFractal(float x, float y, float length, int n, int max);
};

