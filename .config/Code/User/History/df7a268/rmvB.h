#include "util.h"
class Ball{
    const int radius;

    int x;
    int y;
    float *color;

    int vX;
    int vY;

public:

    Ball(int x, int y, int radius, float *color) : x(x), y(y), radius(radius), color(color), vX(0), vY(0){}

    void draw(){
        DrawCircle(x, y, radius, color);
    }

    void move(){
        x += vX;
        y += vY;
    }


};