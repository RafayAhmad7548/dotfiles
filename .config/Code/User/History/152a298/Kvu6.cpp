#include "Food.h"
#include "util.h"

class PinkFood : public Food{

    const int dimension = 20;
    
public:

    PinkFood(int x, int y) : Food(x, y, colors[PINK]){}
    void draw() override{
        DrawSquare(x, y, dimension, color);
    }
    void activatePowerup(Paddle& paddle, Ball& ball) override{
        if(Food::counter == 0) paddle.setWidth(paddle.getWidth()/2);
        cout<<"Pink\n";
    }
    ~PinkFood(){}


};