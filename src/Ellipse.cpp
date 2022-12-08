#include "Ellipse.hpp"


void Elip::draw(){
        drawFractal(ofGetWidth() / 2, ofGetHeight() / 2, this->level,0);}

void Elip::drawFractal(float x, float y, int n, int max){

   if (n == 0) return;

    if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
    
    ofDrawEllipse(x,y,n,150,100);
    ofDrawEllipse(x,y,n,100,150); 
    ofSetColor(ofColor::white);
    
  
    drawFractal(x + 75, y, n - 1, max + 1);
    drawFractal(x - 75, y, n - 1, max + 1);
    drawFractal(x, y + 75, n - 1, max + 1);
    drawFractal(x, y - 75, n - 1, max + 1);
}
