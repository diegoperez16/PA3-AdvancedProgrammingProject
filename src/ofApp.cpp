#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
    animation = false;
    circle = new Circle("CIRCLE",  1, 5);
    tree = new Tree("TREE", 1, 15 );
    t = new TriangleSier("TRIANGLE", 1, 10);
    f = new Fern("FERN", 1,20);
    tetra = new Tetra("TRETRA CIRCLE", 1, 10);
    snow = new SnowFlake("SNOWFLAKE",1,7);
    square = new Square("SQUARE", 1, 10);
    el = new Elip("ELLIPSE", 1, 10);

    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(t);
    fractals.push_back(f);
    fractals.push_back(snow);
    fractals.push_back(tetra);
    fractals.push_back(square);
    fractals.push_back(el);
    
}

//--------------------------------------------------------------
void ofApp::update() {

    if(animation == true){
        for(int i = 0; i<fractals.size(); i++){
            if(i+1 == int(mode)-48){
                fractals[i]->update();
            }
        }
        
    }
}   

//--------------------------------------------------------------
void ofApp::draw() {


    if(mode == '4'){
        ofBackgroundGradient(ofColor(ofColor::black), ofColor(0), OF_GRADIENT_BAR);
    }
    else{
    ofBackgroundGradient(ofColor(ofColor::black), ofColor(ofColor::darkSlateBlue), OF_GRADIENT_LINEAR);
    }
    

    if(animation == true){
        ofDrawBitmapString("ANIMATION: ON ", 50, 50);
    }
    else{
        ofDrawBitmapString("ANIMATION: OFF ", 50, 50);
    }
    
    ofNoFill();
    for(int i = 0; i<fractals.size(); i++){
        if(i+1 == int(mode)-48){
            ofDrawBitmapString("NAME OF FRACTAL: " + ofToString(fractals[i]->getName()), 50, 100);
            ofDrawBitmapString("LEVEL OF FRACTALIZATION: " + ofToString(fractals[i]->getLevel()), 50, 150);
            if(animation == true){
                dynamic_cast<AbstractFractal*>(fractals[i])->setLevel(dynamic_cast<AbstractFractal*>(fractals[i])->getAnimationL());}
            fractals[i]->draw();
        }
    }
}

//--------------------------------------------------------------


void ofApp::keyPressed(int key) {

    if (key >= '1' && key <= '8'){
        mode = key;}
    
    else if (key == OF_KEY_F11)
        ofSetFullscreen(fullscreen++ % 2 == 0);
    else if (key == OF_KEY_ESC)
        ofSetFullscreen(false);

    if(key== OF_KEY_RIGHT){

        for(int i = 0; i<fractals.size(); i++){
            if(i+1 == int(mode)-48){
                if(fractals[i]->getLevel() < fractals[i]->getMAX())
                    fractals[i]->setLevel(fractals[i]->getLevel() + 1);
            }
        }   

    }
    if(key== OF_KEY_LEFT){

        for(int i = 0; i<fractals.size(); i++){
            if(i+1 == int(mode)-48){
                if(fractals[i]->getLevel() > 1)
                    fractals[i]->setLevel(fractals[i]->getLevel() - 1);
            }
        }   
    }
    if(key == ' '){
        animation = !animation;
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
}