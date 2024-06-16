#include "Food.h"
#include "util.h"

class BlueFood : public Food{
    
    const int radius = 10;

public:

    BlueFood(int x, int y) : Food(x, y, colors[BLUE]){}
    void draw() override{
        DrawCircle(x, y, radius, color);
    }
    void activatePowerup(Paddle& paddle, Ball& ball, Ball*& ball1, Ball*& ball2) override{
        if(Food::counter == 0){
            ball.setVX(ball.getVX() < 0 ? -3 : 3);
            ball.setVY(ball.getVY() < 0 ? -3 : 3);
            powerActive = true;
        }
    }
    ~BlueFood(){}

};