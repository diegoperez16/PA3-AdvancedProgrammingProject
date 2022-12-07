#include "Triangle.hpp"


void TriangleSier::draw(){
        float size = 0.88 * ofGetHeight();
        drawFractal((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, this->level, 0);
    }

void TriangleSier::drawFractal(float x, float y, float size, int n, int max){

    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    
     if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);

    drawFractal(x, y, size / 2, n - 1, max+1);
    drawFractal((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, max+1);
    drawFractal((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1, max+1);
}