#pragma once 
#include <string>

using namespace std; 
class Fractal{
    public:
        virtual void draw () = 0;
        virtual string getName () = 0;
        virtual int getLevel ()= 0; 
       
        virtual int getX() const = 0; 
        virtual int getY() const = 0; 
        
        virtual void setX(int x1) = 0; 
        virtual void setY(int y1) = 0; 
    
};

