#include "Food.h"
#include "util.h"

class RedFood : public Food{
    
    const int width = 20;
    const int height = 10;

public:

    RedFood(int x, int y) : Food(x, y, colors[RED]){}
    void draw() override{
        DrawRectangle(x, y , width, height, color);
    }
    void activatePowerup(Paddle& paddle, Ball& ball) override{
    }
    ~RedFood(){}

};