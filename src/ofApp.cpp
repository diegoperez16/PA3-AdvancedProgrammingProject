#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
    circle = new Circle("Circle", (ofGetWidth() / 2), (ofGetHeight() / 2), 0, 0, 0.0);
    tree = new Tree("Tree", ofGetWidth() / 2, ofGetHeight() - 20, 0.0, 0, 0,  0.0 );
    snow = new SnowFlake();
    currentNum = -1;
    color = colores[currentNum];
    // vector<ofColor> colores2(colores.begin(), colores.end());
    
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

   
    ofDrawBitmapString("MODE: " + circle->getName(), 50, 100);
   
    if(mode < '5'){
    ofDrawBitmapString("LEVEL OF FRACTALIZATION: " + ofToString(level), 50, 150);
    ofDrawBitmapString("Color " + ofToString(color), 50, 200);}
    else if(mode == '5'){
    ofDrawBitmapString("LEVEL OF FRACTALIZATION SNOWFLAKE: " + ofToString(snow->getSnowL()), 50, 150);}
    

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        
        circle->draw();
        
    } break;
    case '2': {
        // Tree
        
        tree->draw();
    } break;
    case '3': {
        // Sierpinski Triangle
        float size = 0.88 * ofGetHeight();
        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, level, 0);
    } break;
    case '4':
        // Barnsley Fern

        drawMode4(0, 0, level * 1000, 0);
        break;
    case '5':{
        // Koch 
        
        
        // SnowFlake().draw();

        float size = 0.74 * ofGetHeight();

        glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};


        snow->drawICE(snow->getSnowL(), new SnowFlake(p1, p2));   
        snow->drawICE(snow->getSnowL(), new SnowFlake(p2, p3));
        snow->drawICE(snow->getSnowL(), new SnowFlake(p3, p1));
    }break;
    case '6':{
        drawMode6(((ofGetWidth()) / 2), ofGetHeight() / 2 - 0.4 , 300);
        break;}
    }
}




void ofApp::drawMode3(float x, float y, float size, int n, int max) {
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    
     if(max < colores.size()){
        ofSetColor(colores[max]);
    }
    else{
        max = 0;
        ofSetColor(colores[max]);
    }
    ofDrawTriangle(a, b, c);
    ofSetColor(ofColor::white);

    drawMode3(x, y, size / 2, n - 1, max+1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1, max+1);
    drawMode3((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1, max+1);
}

void ofApp::drawMode4(float x, float y, float n, int max) {
    if (n == 0) return;

    float r = ofRandom(1);

    float px = ofMap(x, -2.1820, 2.6558, 0, ofGetWidth());
    float py = ofMap(y, 0, 9.9983, ofGetHeight(), 0);

    
    
    ofFill();

    if(max < colores.size()){
        ofSetColor(colores[max]);
    }
    else{
        max = 0;
        ofSetColor(colores[max]);
    }
  
    ofDrawCircle(px, py, 0.6);
    ofSetColor(ofColor::white);

    if (r < 0.01)
        drawMode4(0, 0.16 * y, n - 1, max+1);

    else if (r < 0.86)
        drawMode4(0.85 * x + 0.04 * y, -0.04 * x + 0.85 * y + 1.6, n - 1, max+1);

    else if (r < 0.93)
        drawMode4(0.2 * x - 0.26 * y, 0.23 * x + 0.22 * y + 1.6, n - 1,max);

    else
        drawMode4(-0.15 * x + 0.28 * y, 0.26 * x + 0.24 * y + 0.44, n - 1,max);
}

void ofApp::drawMode6(float x, float y, float size) {
    if (size <= 15) {
        return;
    }

    ofDrawEllipse(x,y,size,size);
    ofSetColor(ofColor::white);
    drawMode6(x+size/2, y, size/2);
    drawMode6(x,y+size/2,size/2);
    drawMode6(x-size/2, y, size/2);
    drawMode6(x,y-size/2,size/2);

}
//--------------------------------------------------------------

int ofApp::getLevel(){
    return level;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

    if (key >= '1' && key <= '6'){
        level = 0;
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
                currentNum++;
                color = colores[currentNum];
                circle->setLevel(circle->getLevel() + 1);
            }
        }
        else if(mode == '4'){
            if(level < 50){
                level++;
            }
        }
        else if(mode == '2'){
            if(tree->getLevel() < 15){
                tree->setLevel(tree->getLevel() + 1);
            }
        }
        else if(mode != '4' && mode != '2' && mode != '1' && level < 10 && mode != '5'){
            currentNum++;
            color = colores[currentNum];
            level++;}
    }
    if(key== OF_KEY_LEFT){
        if(level > 0){
            currentNum--;
            color = colores[currentNum];
            level--;
            }
        if(mode == '5' && snow->getSnowL() > 1){
            snow->setSnowL(snow->getSnowL()-1);
            }
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