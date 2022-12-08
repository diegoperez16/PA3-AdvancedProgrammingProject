#include "AbstractFractal.hpp"

AbstractFractal::AbstractFractal(){
};


AbstractFractal::AbstractFractal(string name1, int level1, int dephColor) {
    this->name = name1; 
    this->level = level1; 
    this->MAXLevel = dephColor;
};

void AbstractFractal:: update(){
    animation_level += timer * 0.01;
    if(animation_level  > MAXLevel +1){
        timer = -1;
    }
    else if(animation_level < 1){
        timer = 1;
    }
    
}


AbstractFractal::~AbstractFractal(){
}; 