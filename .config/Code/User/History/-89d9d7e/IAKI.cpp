#include "Food.h"

int Food::counter = 0;
bool Food::powerActive = false;
Food::Food(int x, int y, float *color) : x(x), y(y), color(color){}
void Food::fall(){
    if(y > -20) y -= 5;
    // else return true;
    // return false;
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
void Food::resetPowerup(Paddle& paddle, Ball& ball){
    counter = 0;
    powerActive = false;
    paddle.setWidth(125);
}
Food::~Food(){}