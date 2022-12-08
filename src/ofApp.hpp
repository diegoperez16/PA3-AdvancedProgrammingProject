#pragma once


#include "AbstractFractal.hpp"
#include "Triangle.hpp"
#include "Fern.hpp"
#include "TetraCircle.hpp"
#include <cmath>
#include "Circle.hpp"
#include "Tree.hpp"
#include "SnowFlake.hpp"
#include "Square.hpp"
#include "Ellipse.hpp"


#include "ofMain.h"

class ofApp : public ofBaseApp {
  private:
    bool animation;
    Square* square;
    TriangleSier* t; 
    Fern* f;
    SnowFlake* snow;
    Circle* circle;
    Tree* tree;
    Tetra* tetra;
    Elip* el;

    char mode = '1';
    unsigned int fullscreen;

  public:

    vector<AbstractFractal*> fractals;
    
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
