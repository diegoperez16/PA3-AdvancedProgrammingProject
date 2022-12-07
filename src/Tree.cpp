#include "Tree.hpp"


void Tree::draw(){
        float length = 0.31 * ofGetHeight();
        drawFractal(ofGetWidth() / 2, ofGetHeight() - 20, 1.5*PI, this->level, 0,  length);
        drawFractal(ofGetWidth() / 2 + 400, ofGetHeight() - 20, 1.5*PI, this->level, 0,  length/4);
        drawFractal(ofGetWidth() / 2 - 400, ofGetHeight() - 20, 1.5*PI, this->level, 0,  length/4);
}

void Tree::drawFractal(float x, float y, float rad, int n, int max, float length){
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    
     if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white);


    drawFractal(x2, y2, rad + 0.2 * PI, n-1 , max+1, 0.7 * length);
    drawFractal(x2, y2, rad - 0.2 * PI,  n-1, max+1, 0.7 * length);


}


