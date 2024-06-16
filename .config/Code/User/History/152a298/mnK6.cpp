#include "Food.h"
#include "util.h"

class PinkFood : public Food{

    const int dimension = 20;
    
public:

    PinkFood(int x, int y) : Food(x, y, colors[PINK]){}
    void draw() override{
        DrawSquare(x, y, dimension, color);
    }
    void activatePowerup(Paddle& paddle, Ball**& balls) override{
        if(Food::counter == 0){
            if(paddle.getWidth() > 62) paddle.setWidth(paddle.getWidth()/2);
            powerActive = true;
        }
    }
    ~PinkFood(){}


};