#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
    circle_in_vector = false;
    circle = new Circle("CIRCLE", (ofGetWidth() / 2), (ofGetHeight() / 2), 1, 0, 0.0);
    tree = new Tree("TREE", ofGetWidth() / 2, ofGetHeight() - 20, 1, 0, 0,  0.0 );
    t = new TriangleSier("TRIANGLE", 0.0, 0.0, 1, 0,0);
    f = new Fern("FERN", 0.0,0.0,1,0);
    tetra = new Tetra("TRETRA CIRCLE", 0.0,0.0, 1,0);
    snow = new SnowFlake();

    fractals.push_back(circle);
    fractals.push_back(tree);
    fractals.push_back(t);
    fractals.push_back(f);
    fractals.push_back(tetra);
    
}

//--------------------------------------------------------------
void ofApp::update() {

}   

//--------------------------------------------------------------
void ofApp::draw() {

    if(mode == '4'){
        ofBackgroundGradient(ofColor(ofColor::black), ofColor(0), OF_GRADIENT_BAR);
    }
    else{
    ofBackgroundGradient(ofColor(ofColor::black), ofColor(ofColor::darkSlateBlue), OF_GRADIENT_LINEAR);
    }
    


    if(mode == '5'){

        // Koch 

        ofDrawBitmapString("NAME OF FRACTAL: SNOWFLAKE", 50, 100);
        ofDrawBitmapString("LEVEL OF FRACTALIZATION: " + ofToString(snow->getSnowL()), 50, 150);


        float size = 0.74 * ofGetHeight();

        glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};


        snow->drawICE(snow->getSnowL(), new SnowFlake(p1, p2));   
        snow->drawICE(snow->getSnowL(), new SnowFlake(p2, p3));
        snow->drawICE(snow->getSnowL(), new SnowFlake(p3, p1));}
    
    // ofDrawBitmapString("NAME OF FRACTAL IN VECTOR : " + ofToString(fractals[fpos]->getName()), 50, 300);
    
    ofNoFill();
    for(int i = 0; i<fractals.size(); i++){
        if(i+1 == int(mode)-48 && mode != '5'){
            ofDrawBitmapString("NAME OF FRACTAL: " + ofToString(fractals[i]->getName()), 50, 100);
            ofDrawBitmapString("LEVEL OF FRACTALIZATION: " + ofToString(fractals[i]->getLevel()), 50, 150);
            fractals[i]->draw();
        }
        else if(i+1 == 5 && mode == '6'){
            ofDrawBitmapString("NAME OF FRACTAL IN VECTOR : " + ofToString(fractals[i]->getName()), 50, 100);
            ofDrawBitmapString("LEVEL OF FRACTALIZATION: " + ofToString(fractals[i]->getLevel()), 50, 150);
            fractals[i]->draw();
        }
    }

}

//--------------------------------------------------------------

//PONER ESTO MAS LINDO:

void ofApp::keyPressed(int key) {

    if (key >= '1' && key <= '6'){
        mode = key;}
    
    else if (key == OF_KEY_F11)
        ofSetFullscreen(fullscreen++ % 2 == 0);
    else if (key == OF_KEY_ESC)
        ofSetFullscreen(false);

    if(key== OF_KEY_RIGHT){
        if(mode == '5'){
            if(snow->getSnowL() < 8){
                
            snow->setSnowL(snow->getSnowL() + 1);
            }
        }
        if(mode == '1')
        {
            if(circle->getLevel() < 5){
                circle->setLevel(circle->getLevel() + 1);
            }
        }
        else if(mode == '4'){
            if(f->getLevel() < 1500){
                f->setLevel(f->getLevel() + 1);
            }
        }
        else if(mode == '2'){
            if(tree->getLevel() < 15){
                tree->setLevel(tree->getLevel() + 1);
            }
        }
        else if(mode== '3'){
            if(t->getLevel() < 10){
                t->setLevel(t->getLevel() + 1);
            }
        }
        else if(mode == '6'){
            if(tetra->getLevel() < 10){
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
        else if(mode == '5' && snow->getSnowL() > 1){
            snow->setSnowL(snow->getSnowL()-1);
            }
        else if(mode == '6'){
            if(tetra->getLevel() > 1){
                tetra->setLevel(tetra->getLevel() - 1);
            }
        }
    }
    if(key == 'w'){
        fpos++;
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