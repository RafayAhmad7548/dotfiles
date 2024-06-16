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
        if(Food::counter == 0){
            for(int i=0;i<3;i++){
                if(balls[i] == nullptr){
                    balls[i] = new Ball()
                }
            }
        }
    }
    ~YellowFood(){}

};