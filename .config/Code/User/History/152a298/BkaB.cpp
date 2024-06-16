#include "Food.h"
#include "util.h"

class PinkFood : public Food{

    const int dimension = 20;
    
public:

    PinkFood(int x, int y) : Food(x, y, colors[PINK]){}
    void draw() override{
        DrawSquare(x, y, dimension, color);
    }
    void activatePowerup(Paddle& paddle, Ball& ball, Ball*& ball1, Ball*& ball2) override{
        if(Food::counter == 0){
            paddle.setWidth(paddle.getWidth()/2);
            powerActive = true;
        }
    }
    ~PinkFood(){}


};