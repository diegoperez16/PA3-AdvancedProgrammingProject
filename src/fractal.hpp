#pragma once 

class Fractal{
    public:
        virtual ~Fractal () {};
        
        virtual void draw () = 0;
        virtual void getName () = 0;
        virtual void getLevel ()= 0; 
};

