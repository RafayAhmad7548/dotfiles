#include "Food.h"

int Food::counter = 0;
bool Food::powerActive = false;
Food::Food(int x, int y, float *color) : x(x), y(y), color(color){}
void Food::fall(){
    if(y > -20) y -= 5;
}

int Food::getX(){
    return x;
}
int Food::getY(){
    return y;
}
int Food::getCounter(){
    return counter;
}
bool Food::getPowerActive(){
    return powerActive;
}

void Food::count(){
    counter++;
}
void Food::resetPowerup(Paddle& paddle, Ball**& balls){
    counter = 0;
    powerActive = false;
    paddle.setWidth(125);
    for(int i=0;i<3;i++){
        ball.setVX(ball.getVX() < 0 ? -5 : 5);
        ball.setVY(ball.getVY() < 0 ? -5 : 5);
        
    }
    // if(ball1 != nullptr) delete ball1;
    // if(ball2 != nullptr) delete ball2;
}
Food::~Food(){}