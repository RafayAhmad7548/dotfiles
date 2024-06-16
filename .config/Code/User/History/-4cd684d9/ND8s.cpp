#include "Food.h"
#include "util.h"

class GreenFood : public Food{

    const int height = 20;
    const int width = 10;

public: 

    GreenFood(int x, int y) : Food(x, y, colors[GREEN]){}

    void draw(){
        DrawTriangle(x, y, x-width, y+height, x+width, y+height, color);
    }
    void fall(){
        y -= 5;
    }
    
    ~GreenFood(){}

};