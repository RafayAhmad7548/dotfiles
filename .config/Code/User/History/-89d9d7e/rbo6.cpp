#include "Food.h"

Food::Food(int x, int y, float *color) : x(x), y(y), color(color){}
void Food::fall(){
    y -= 5;
}
Food::~Food(){}