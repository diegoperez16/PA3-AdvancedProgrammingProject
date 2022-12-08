#pragma once

#include <cmath>
#include "SnowFlake.hpp"
#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:

    int currentNum;
    ofColor color;
    SnowFlake* snow;
    bool circle = false;
    bool fern = false;
    
    int level = 0;
    char mode = '1';
    float angle = 0;
    unsigned int fullscreen;

  public:

    vector<ofColor> colores{ ofColor::red, ofColor::blue, ofColor:: green, ofColor:: yellow, ofColor::white, ofColor::pink, ofColor::orange, ofColor::aqua, ofColor::purple, ofColor::teal};
    
    void setup();
    void update();
    void draw();
    int getLevel();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void drawMode1(float x, float y, float r, int n, int max);
    void drawMode2(float x, float y, int n, float length, float rad, int max);
    void drawMode3(float x, float y, float size, int n, int max);
    void drawMode4(float x, float y, float n, int max);
    void drawMode6(float x, float y, float length, int n, int max);
    void drawMode7(float x, float y, int n, int max);
     
    
};
