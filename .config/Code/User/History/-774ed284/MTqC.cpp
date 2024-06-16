#include "Food.h"
#include "util.h"

class BlueFood : public Food{
    
    const int radius = 10;

public:

    BlueFood(int x, int y) : Food(x, y, colors[BLUE]){}
    void draw() override{
        DrawCircle(x, y, radius, color);
    }
    void activatePowerup(Paddle& paddle, Ball**& balls) override{
        if(Food::counter == 0){
            for(int i=0;i<3;i++){
                if(balls[i] != nullptr){
                    balls[i]->setVX(balls[i]->getVX() < 0 ? -3 : 3);
                    balls[i]->setVY(balls[i]->getVY() < 0 ? -3 : 3);
                }
            }
            powerActive = true;
        }
    }
    ~BlueFood(){}

};