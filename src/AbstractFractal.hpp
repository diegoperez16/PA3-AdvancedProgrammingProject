#pragma once 
#include <string>
#include "ofMain.h"
#include "fractal.hpp"

class AbstractFractal: public Fractal{
    protected: 
        int level;
        int MAXLevel;
        string name; 
        float animation_level = 1;
        int timer = 1;
        float changeAngle = 0.2;
        



    public: 
        AbstractFractal();
        ~AbstractFractal(); 
        vector<ofColor> colores2{ ofColor::red, ofColor::blue, ofColor:: green, ofColor:: yellow, ofColor::white, ofColor::pink, ofColor::orange, ofColor::aqua, ofColor::purple, ofColor::teal};
        AbstractFractal(string name1, int level1, int dephColor);

        void update();

        string getName () {return name;} 
        int getLevel () {return level;} 
        float getAnimationL(){return animation_level;}
        float getAngle() { return changeAngle;}

        float setAngle(float change){ changeAngle = change;}

        void  setLevel(int l) { 
            if(l < 1){l = 1;
            }
            else if(l > MAXLevel){l = MAXLevel;}
            level = l;}

        int getMAX(){return MAXLevel;}
    
}; 