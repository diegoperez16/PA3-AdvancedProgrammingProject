#include "SnowFlake.hpp"


void SnowFlake::draw() {
    
        float size = 0.74 * ofGetHeight();

        glm::vec2 p1 = {(ofGetWidth() - size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p2 = {(ofGetWidth() + size) / 2, (ofGetHeight() - size * sin(PI / 3)) / 2 + 0.15 * size};
        glm::vec2 p3 = {ofGetWidth() / 2, (ofGetHeight() + size * sin(PI / 3)) / 2 + 0.15 * size};


        drawFractal(this->level, new SnowFlake("", 0.0, 0.0 ,0,0 ,p1, p2));   
        drawFractal(this->level, new SnowFlake("", 0.0, 0.0 ,0,0 ,p2, p3));
        drawFractal(this->level, new SnowFlake("", 0.0, 0.0 ,0,0 ,p3, p1));
}
void SnowFlake::drawFractal(int n, SnowFlake *flake) {
   
    if (n < 2)
        ofDrawLine(flake->getStart(), flake->getEnd());
    else {
        drawFractal(n - 1, new SnowFlake("", 0.0, 0.0 ,0,0 , flake->getA(), flake->getB()));
        drawFractal(n - 1, new SnowFlake("", 0.0, 0.0 ,0,0 ,flake->getB(), flake->getC()));
        drawFractal(n - 1, new SnowFlake("", 0.0, 0.0 ,0,0 ,flake->getC(), flake->getD()));
        drawFractal(n - 1, new SnowFlake("", 0.0, 0.0 ,0,0 ,flake->getD(), flake->getE()));
    }
    delete flake;
}

glm::vec2 SnowFlake::getA() { return start; }

glm::vec2 SnowFlake::getB() {
    double x = (end.x - start.x) / 3.0 + start.x;
    double y = (end.y - start.y) / 3.0 + start.y;
    return {x, y};
}

glm::vec2 SnowFlake::getC() {
    glm::vec2 v1 = this->getB();
    glm::vec2 v2 = {(end.x - start.x) / 3.0, (end.y - start.y) / 3.0};

    auto rotate = [](glm::vec2 v, double angle) {
        return glm::vec2{v.x * cos(angle) - v.y * sin(angle), v.x * sin(angle) + v.y * cos(angle)};
    };
    v2 = rotate(v2, -PI / 3);
    return {v1.x + v2.x, v1.y + v2.y};
}

glm::vec2 SnowFlake::getD() {
    double x = 2.0 * (end.x - start.x) / 3.0 + start.x;
    double y = 2.0 * (end.y - start.y) / 3.0 + start.y;
    return {x, y};
}

glm::vec2 SnowFlake::getE() { return end; }