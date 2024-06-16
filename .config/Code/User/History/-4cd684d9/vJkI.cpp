#include "Food.h"
#include "util.h"

class GreenFood : public Food{

    const int height = 20;
    const int width = 10;

public: 

    GreenFood(int x, int y) : Food(x, y, colors[GREEN]){}

    void draw() override{
        DrawTriangle(x, y, x-width, y+height, x+width, y+height, color);
    }

    void activatePowerup(Paddle& paddle, Ball**& balls) override{
        if(Food::counter == 0){
            if(paddle.getWidth() < 250) paddle.setWidth(paddle.getWidth()*2);
            powerActive = true;
        }
    }
    
    ~GreenFood(){}

};