#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Tree: public AbstractFractal {
    private: 
  public:
    Tree(string name1, int level1, int dephColor) : AbstractFractal(name1,level1, dephColor){
    };

    void draw();

    void drawFractal(float x, float y, float rad, int n, int max, float length);


};










