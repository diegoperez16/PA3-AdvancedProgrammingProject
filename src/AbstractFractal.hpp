#pragma once 
#include <string>
#include "ofMain.h"
#include "fractal.hpp"

class AbstractFractal: public Fractal{
    protected: 
        float x; 
        float y; 
        int level;
        int colorXLevel;
        string name; 



    public: 
        ~AbstractFractal(); 
        vector<ofColor> colores2{ ofColor::red, ofColor::blue, ofColor:: green, ofColor:: yellow, ofColor::white, ofColor::pink, ofColor::orange, ofColor::aqua, ofColor::purple, ofColor::teal};
        AbstractFractal(string name1, float x1, float y1, int level1, int dephColor) {
            this->name = name1; 
            this->x = x1; 
            this->y = y1;
            this->level = level1; 
            this->colorXLevel = dephColor;
        };

        void draw () {}; 
        string getName () {return name;} 
        int getLevel () {return level;} 
        float getX(){return x;}
        float getY(){return y;}

        void  setX(float x2) {x = x2;}
        void  setY(float y2) { y = y2;}

        int getColorL(){return colorXLevel;}
        void  setColorL(int color){ colorXLevel = color;}
    
}; 