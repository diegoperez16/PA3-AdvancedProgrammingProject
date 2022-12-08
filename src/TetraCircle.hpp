#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Tetra: public AbstractFractal {
    private: 
  public:
    Tetra(string name1,  int level1, int dephColor) : AbstractFractal(name1,level1, dephColor){
    };

    void draw();

    void drawFractal(float x, float y, float size, int n, int max);
};










