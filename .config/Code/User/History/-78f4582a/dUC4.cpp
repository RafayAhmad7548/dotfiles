#include "Food.h"
#include "util.h"

class YellowFood : public Food{

    const int dimension = 20;
    
public:

    YellowFood(int x, int y) : Food(x, y, colors[YELLOW]){}
    void draw() override{
        DrawSquare(x, y, dimension, color);
    }
    void activatePowerup(Paddle& paddle, Ball**& balls) override{
        // if(Food::counter == 0){
        //     ball1 = new Ball(ball.getX(), ball.getY(), ball.getRadius(), colors[RED]);
        //     ball2 = new Ball(ball.getX(), ball.getY(), ball.getRadius(), colors[RED]);
        // }
    }
    ~YellowFood(){}

};