#include "TetraCircle.hpp"


void Tetra::draw(){
        drawFractal((ofGetWidth()) / 2, ofGetHeight() / 2 - 0.4 , 500, this->level, 0);}

void Tetra::drawFractal(float x, float y, float size, int n, int max){

    if ( n == 0) {
        return;
    }

    if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
    ofDrawEllipse(x,y,size,size);
    ofSetColor(ofColor::white);
    drawFractal(x+size/2, y, size/2, n-1, max+1);
    drawFractal(x,y+size/2,size/2, n-1, max+1);
    drawFractal(x-size/2, y, size/2, n-1, max+1);
    drawFractal(x,y-size/2,size/2,n-1, max+1);
;
}