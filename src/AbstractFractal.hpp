#include "fractal.hpp"

class AbstractFractal: public Fractal{
    public: 
        ~AbstractFractal(); 
        void draw () {}; 
        string getName () {}; 
        int getLevel () {}; 


    
}; 