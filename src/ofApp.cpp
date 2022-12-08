#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetEscapeQuitsApp(false);
    fullscreen = 0;
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

    ofDrawBitmapString("MODE: " + ofToString(mode), 50, 100);
    if(mode < '5'){
    ofDrawBitmapString("LEVEL OF FRACTALIZATION: " + ofToString(level), 50, 150);
    ofDrawBitmapString("Color " + ofToString(color), 50, 200);}
    else if(mode == '5'){
    ofDrawBitmapString("LEVEL OF FRACTALIZATION SNOWFLAKE: " + ofToString(snow->getSnowL()), 50, 150);}
    

    ofNoFill();
    switch (mode) {
    case '1': {
        // Circle
        
        float r = 0.31 * ofGetHeight();
        angle += 0.01;
       
        drawMode1(ofGetWidth() / 2, ofGetHeight() / 2, r, level, 0);
        
    } break;
    case '2': {
        // Tree
        
        float length = 0.31 * ofGetHeight();
        drawMode2(ofGetWidth() / 2, ofGetHeight() - 20, level, length, 1.5 * PI, 0);
        drawMode2((ofGetWidth() / 2) + 400, ofGetHeight() - 20, level, length/4, 1.5 * PI, 0);
        drawMode2((ofGetWidth() / 2) - 400, ofGetHeight() - 20, level, length/4, 1.5 * PI, 0);
    } break;
    case '3': {
        // Sierpinski Triangle
        float size = 0.88 * ofGetHeight();
        drawMode3((ofGetWidth() - size) / 2, ofGetHeight() / 2 - 0.4 * size, size, level, 0);
    } break;
    case '4':{
        // Barnsley Fern

        drawMode4(0, 0, level * 1000, 0);
    }    break;
    case '5': {
        // Koch 
        
        
        // SnowFlake().draw();

        float size = 0.74 * ofGetHeight();

        glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};


        snow->drawICE(snow->getSnowL(), new SnowFlake(p1, p2));   
        snow->drawICE(snow->getSnowL(), new SnowFlake(p2, p3));
        snow->drawICE(snow->getSnowL(), new SnowFlake(p3, p1));
    } break;
    case '6': {

        //new fractal: 
        //Center
        drawMode6(ofGetWidth() / 2, ofGetHeight() / 2,ofGetHeight() * 0.5 / 2.0 , level, 0);
        
    } break; 
    }
}
void ofApp::drawMode1(float x, float y, float r, int n, int max) {
    if (n == 0) return;

    int delta = r * 0.35;

    
    if(max < colores.size()){
        ofSetColor(colores[max]);
    }
    else{
        max = 0;
        ofSetColor(colores[max]);
    }
    ofDrawCircle(x, y, r);
    ofSetColor(ofColor::white);



    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    drawMode1(x + r * cos(angle1), y + r * sin(angle1), delta, n - 1, max + 1);
    drawMode1(x + r * cos(angle2), y + r * sin(angle2), delta, n - 1, max + 1);
    drawMode1(x + r * cos(angle3), y + r * sin(angle3), delta, n - 1, max + 1 );
    drawMode1(x + r * cos(angle4), y + r * sin(angle4), delta, n - 1, max + 1);
    drawMode1(x + r * cos(angle5), y + r * sin(angle5), delta, n - 1, max + 1);
    drawMode1(x + r * cos(angle6), y + r * sin(angle6), delta, n - 1, max +1);
}

void ofApp::drawMode2(float x, float y, int n, float length, float rad, int max) {
    if (n == 0) return;

    float x2 = x + length * cos(rad);
    float y2 = y + length * sin(rad);

    // float x3 = x + length * cos(rad);
    // float y3 = y + length * sin(rad);

    
     if(max < colores.size()){
        ofSetColor(colores[max]);
    }
    else{
        max = 0;
        ofSetColor(colores[max]);
    }
    ofDrawLine(x, y, x2, y2);
    ofSetColor(ofColor::white);

    // ofDrawLine(x + 600, y + 150, x3 + 600 , y3 + 150);

    drawMode2(x2, y2, n - 1, 0.7 * length, rad + 0.2 * PI, max + 1);
    drawMode2(x2, y2, n - 1,  0.7 * length, rad - 0.2 * PI, max + 1);

    // drawMode2(x3 + 600, y3 + 150, n - 1, (0.7 * length)/2, (rad + 0.2 * PI)/2);
    // drawMode2(x3 + 600, y3  + 150, n - 1,  (0.7* length)/2, (rad - 0.2 * PI)/2);
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

    drawMode3(x, y, size / 2, n - 1, max +1);
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

//Draws the new fractal 
void ofApp::drawMode6(float x, float y, float length, int n, int max) {
    if (n == 0) return;

    if(max < colores.size()){
        ofSetColor(colores[max]);
    }
    else{
        max = 0;
        ofSetColor(colores[max]);
    }
    
    ofDrawRectangle(x - length, y - length, length * 2, length * 2);
    ofSetColor(ofColor::white);
    
    //Left Corner
    drawMode6(x - length, y - length, length /2, n - 1, max + 1);
    //Right Corner 
    drawMode6(x + length, y - length, length /2, n - 1, max + 1);
    //Left Corner down 
    drawMode6(x - length, y + length, length /2, n - 1, max + 1);
    //Right Corner down 
    drawMode6(x + length, y + length, length /2, n - 1, max + 1);
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
            if(level < 5){
                currentNum++;
                color = colores[currentNum];
                level++;
            }
        }
        else if(mode == '4'){
            if(level < 50){
                level++;
            }
        }
        else if(mode != '4' && mode != '1' && level < 10 && mode != '5'){
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