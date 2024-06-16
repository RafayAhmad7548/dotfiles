#include "util.h"
class Paddle{
    const int height;
    const int y;

    int width;
    int x;
    float *color;

public:

    Paddle(int width, int x, float *color) : height(25), y(10), width(width), x(x), color(color){
        DrawRectangle(x, y, width, height, color);
    }

    Paddle& setX(int x){
        if(x < 10) this->x = 10;
        else if(x > 1010) this->x = 1010;
        else this->x = x;
        return *this;
    }


};