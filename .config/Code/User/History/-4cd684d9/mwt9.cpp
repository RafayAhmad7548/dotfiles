#include "Food.h"
#include "util.h"

class GreenFood : public Food{

    int height;
    int width;

public: 

    GreenFood(int x, int y, float *color) : width(width), height(height), Food(x, y, color){}

    void draw(){
        DrawTriangle(x, y, x-width, y+height, x+width, y+height, color);
    }
    void fall(){
        y -= 5;
    }
    
    ~GreenFood(){}

};