#include "SnowFlake.hpp"


SnowFlake::SnowFlake() {
}

SnowFlake::SnowFlake(glm::vec2 start, glm::vec2 end) {
    this->start = start;
    this->end = end;
}

void SnowFlake::draw() {
    
}
void SnowFlake::drawICE(int n, SnowFlake *flake) {
   
    if (n < 2)
        ofDrawLine(flake->getStart(), flake->getEnd());
    else {
        drawICE(n - 1, new SnowFlake(flake->getA(), flake->getB()));
        drawICE(n - 1, new SnowFlake(flake->getB(), flake->getC()));
        drawICE(n - 1, new SnowFlake(flake->getC(), flake->getD()));
        drawICE(n - 1, new SnowFlake(flake->getD(), flake->getE()));
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