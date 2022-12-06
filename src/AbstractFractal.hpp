#include "fractal.hpp"

class AbstractFractal: public Fractal{
    protected: 
        float x; 
        float y; 
        int level;
        int colorXLevel;
        string name; 



    public: 
        ~AbstractFractal(); 
        AbstractFractal(string name1, float x1, float y1, int level1, int dephColor) {
            this->name = name1; 
            this->x = x1; 
            this->y = y1;
            this->level = level1; 
            this->colorXLevel = dephColor;
        };

       virtual void draw () {}; 
        string getName () {return name;} 
        int getLevel () {return level;} 
       
        int getX(){return x;}
        int getY(){return y;}

        void  setX(float x2) {x = x2;}
        void  setY(float y2) { y = y2;}

        int getColorL(){return colorXLevel;}
        void  setColorL(int color){ colorXLevel = color;}
    
}; 