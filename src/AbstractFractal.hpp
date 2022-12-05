#include "fractal.hpp"

class AbstractFractal: public Fractal{
    protected: 
        int x; 
        int y; 
        int level;
        string name; 


    public: 
        ~AbstractFractal(); \
        AbstractFractal(string name1, int x1, int y1, int level1) {
            this->name = name1; 
            this->x = x1; 
            this->y = y1;
            this->level = level1; 
        };

        void draw () {}; 
        virtual void drawFractal() = 0;
        string getName () {return name;} 
        int getLevel () {return level;} 
       
        int getX(){return x;}
        int getY(){return y;}

        void  setX(int x2) {x = x2;}
        void  setY(int y2) { y = y2;}
    
}; 