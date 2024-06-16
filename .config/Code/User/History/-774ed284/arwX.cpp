#include "Food.h"
#include "util.h"

class BlueFood : public Food{
    
    const int radius = 10;

public:

    BlueFood(int x, int y) : Food(x, y, colors[BLUE]){}
    void draw() override{
        DrawCircle(x, y, radius, color);
    }
    void activatePowerup(Paddle& paddle, Ball& ball) override{
        ball.setVX(ball.getVX() < 0 ? -3 : 3);
        ball.setVY(ball.getVY() < 0 ? -3 : 3);
    }
    ~BlueFood(){}

};