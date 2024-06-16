#include "Food.h"
#include "util.h"

class GreenFood : public Food{

    const int height = 10;
    const int width = 5;

public: 

    GreenFood(int x, int y, float *color) : Food(x, y, color){}

    void draw(){
        DrawTriangle(x, y, x-width, y+height, x+width, y+height, color);
    }
    void fall(){
        y -= 5;
    }
    
    ~GreenFood(){}

};