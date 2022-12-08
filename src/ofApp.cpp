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

    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(t);
    fractals.push_back(f);
    fractals.push_back(snow);
    fractals.push_back(tetra);
    
}

//--------------------------------------------------------------
void ofApp::update() {

    if(animation == true){
        for(int i = 0; i<fractals.size(); i++){
            if(i+1 == int(mode)-48){
                fractals[i]->update();
            }
            // else if(i+1 == 5 && mode == '6'){
            //     fractals[i]->update();
            // }
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

    if (key >= '1' && key <= '6'){
        mode = key;}
    
    else if (key == OF_KEY_F11)
        ofSetFullscreen(fullscreen++ % 2 == 0);
    else if (key == OF_KEY_ESC)
        ofSetFullscreen(false);

    if(key== OF_KEY_RIGHT){
        if(mode == '1')
        {
            if(circle->getLevel() < circle->getMAX()){
                circle->setLevel(circle->getLevel() + 1);
            }
        }
        
        else if(mode == '2'){
            if(tree->getLevel() < tree->getMAX()){
                tree->setLevel(tree->getLevel() + 1);
            }
        }
        else if(mode== '3'){
            if(t->getLevel() < t->getMAX()){
                t->setLevel(t->getLevel() + 1);
            }
        }
        else if(mode == '4'){
            if(f->getLevel() < f->getMAX()){
                f->setLevel(f->getLevel() + 1);
            }
        }
        if(mode == '5'){
            if(snow->getLevel() < snow->getMAX()){
                
            snow->setLevel(snow->getLevel() + 1);
            }
        }
        else if(mode == '6'){
            if(tetra->getLevel() < tetra->getMAX()){
                tetra->setLevel(tetra->getLevel() + 1);
            }
        }}
    if(key== OF_KEY_LEFT){
        if(mode == '1'){
            if(circle->getLevel() > 1){
                circle->setLevel(circle->getLevel() - 1);
            }
        }
        else if(mode == '2'){
            if(tree->getLevel() > 1){
                tree->setLevel(tree->getLevel() - 1);
            }
        }
        else if(mode == '3'){
            if(t->getLevel() > 1){
                t->setLevel(t->getLevel() - 1);
            }
        }
        else if(mode == '4'){
            if(f->getLevel() > 1){
                f->setLevel(f->getLevel() - 1);
            }
        }
        else if(mode == '5' && snow->getLevel() > 1){
            snow->setLevel(snow->getLevel()-1);
            }
        else if(mode == '6'){
            if(tetra->getLevel() > 1){
                tetra->setLevel(tetra->getLevel() - 1);
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