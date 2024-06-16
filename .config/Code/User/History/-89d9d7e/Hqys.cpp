#include "Food.h"

Food::Food(int x, int y, float *color) : x(x), y(y), color(color){}
bool Food::fall(){
    if(y > 0) y -= 5;
    else return true;
    return false;
}
Food::~Food(){}