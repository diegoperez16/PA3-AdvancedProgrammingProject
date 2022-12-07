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















// void ofApp::drawMode2(float x, float y, int n, float length, float rad, int max) {
//     if (n == 0) return;

//     float x2 = x + length * cos(rad);
//     float y2 = y + length * sin(rad);

//     // float x3 = x + length * cos(rad);
//     // float y3 = y + length * sin(rad);

    
//      if(max < colores.size()){
//         ofSetColor(colores[max]);
//     }
//     else{
//         max = 0;
//         ofSetColor(colores[max]);
//     }
//     ofDrawLine(x, y, x2, y2);
//     ofSetColor(ofColor::white);

//     // ofDrawLine(x + 600, y + 150, x3 + 600 , y3 + 150);

//     drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI, max + 1);
//     drawMode2(x2, y2, n - 1,  0.7 * length, rad - 0.2 * PI, max + 1);

//     // drawMode2(x3 + 600, y3 + 150, n - 1, (0.7 * length)/2, (rad + 0.2 * PI)/2);
//     // drawMode2(x3 + 600, y3  + 150, n - 1,  (0.7* length)/2, (rad - 0.2 * PI)/2);
// }