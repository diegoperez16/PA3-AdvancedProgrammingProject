#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class Elip: public AbstractFractal {
  private: 
  public:
    Elip(string name1,  int level1, int dephColor) : AbstractFractal(name1,level1, dephColor){
    };

    void draw();

    void drawFractal(float x, float y,int n, int max);
};