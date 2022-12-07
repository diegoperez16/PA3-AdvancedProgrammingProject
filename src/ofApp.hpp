#pragma once
#include "Triangle.hpp"
#include "Fern.hpp"
#include "TetraCircle.hpp"
#include <cmath>
#include "Circle.hpp"
#include "Tree.hpp"
#include "SnowFlake.hpp"
#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:

    TriangleSier* t; 
    Fern* f;
    int currentNum;
    ofColor color;
    SnowFlake* snow;
    Circle* circle;
    Tree* tree;
    Tetra* tetra;
    // bool circle = false;
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

    void drawMode6(float x, float y, float size, int n, int max);
    
};
