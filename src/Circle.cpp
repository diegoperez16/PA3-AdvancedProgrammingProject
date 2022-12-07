#include "Circle.hpp"


void Circle::draw(){
    float r = 0.31 * ofGetHeight();
    this->angle += 0.01;
       
    drawFractal(ofGetWidth() / 2, ofGetHeight() / 2, r, this->level, 0);
}

void Circle::drawFractal(float x, float y, float r, int n, int max){
    if (n == 0) return;

    int delta = r * 0.35;

    
    if(max < colores2.size()){
        ofSetColor(colores2[max]);
    }
    else{
        max = 0;
        ofSetColor(colores2[max]);
    }
    ofDrawCircle(x, y, r);
    ofSetColor(ofColor::white);



    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawFractal(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1, max + 1);
    drawFractal(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1, max + 1);
    drawFractal(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1, max + 1 );
    drawFractal(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1, max + 1);
    drawFractal(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1, max + 1);
    drawFractal(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1, max +1);
}
