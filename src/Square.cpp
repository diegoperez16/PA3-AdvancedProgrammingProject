#include "Square.hpp"


void Square::draw(){
        drawFractal(ofGetWidth() / 2, ofGetHeight() / 2, ofGetHeight() * 0.5 / 3.0 , this->level, 0);
}

void Square::drawFractal(float x, float y, float length, int n, int max){

    if (n == 0) return;


    if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
    
    ofDrawRectangle(x - length, y - length, length * 2, length * 2);
    ofSetColor(ofColor::white);
    
    //Left Corner
    drawFractal(x - length, y - length, length /2, n - 1, max + 1);
    //Right Corner 
    drawFractal(x + length, y - length, length /2, n - 1, max + 1);
    //Left Corner down 
    drawFractal(x - length, y + length, length /2, n - 1, max + 1);
    //Right Corner down 
    drawFractal(x + length, y + length, length /2, n - 1, max + 1);
}
