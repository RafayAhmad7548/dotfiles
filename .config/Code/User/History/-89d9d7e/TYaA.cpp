#include "Food.h"

Food::counter = 0;
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
Food::~Food(){}