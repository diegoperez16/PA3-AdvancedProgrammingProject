#include "Fern.hpp"


void Fern::drawFractal(float x, float y, int n, int max){
     if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    
    
    ofFill();

    if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
  
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        drawFractal(0, 0.16 * y, n - 1, max+1);

    else if (r < 0.86)
        drawFractal(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1, max+1);

    else if (r < 0.93)
        drawFractal(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1,max);

    else
        drawFractal(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1,max);
}

void Fern::draw(){
       
    drawFractal(0, 0, this->level * 1000, 0);
    
}