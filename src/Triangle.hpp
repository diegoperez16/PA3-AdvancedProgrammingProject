#pragma once

#include "AbstractFractal.hpp"
#include "ofMain.h"
#include <cmath>


class TriangleSier: public AbstractFractal {
    
  private: 
  public:
    TriangleSier(string name1, int level1, int dephColor) : AbstractFractal(name1,level1, dephColor){
    };

    void draw();

    void drawFractal(float x, float y, float size, int n, int max);
};














// void ofApp::drawMode3(float x, float y, float size, int n, int max) {
//     if (n == 0) {
//         return;
//     }

//     ofPoint a(x, y);
//     ofPoint b(x + size, y);
//     ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    
//      if(max < colores.size()){
//         ofSetColor(colores[max]);
//     }
//     else{
//         max = 0;
//         ofSetColor(colores[max]);
//     }
//     ofDrawTriangle(a, b, c);
//     ofSetColor(ofColor::white);

//     drawMode3(x, y, size / 2, n - 1, max+1);
//     drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, max+1);
//     drawMode3((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1, max+1);
// }