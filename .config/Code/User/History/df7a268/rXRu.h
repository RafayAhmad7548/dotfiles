#include "util.h"
class Ball{
    const int radius;

    int x;
    int y;
    float *color;

    int vX;
    int vY;

public:

    Ball(int x, int y, int radius, float *color) : x(x), y(y), radius(radius), color(color), vX(5), vY(5){}

    void draw(){
        DrawCircle(x, y, radius, color);
    }

    void move(){
        x += vX;
        y += vY;
    }

    void checkBoundCollision(){
        if(x - radius < 0 || x + radius > 1020) vX *= -1;
        if(y + radius > 840) vY *= -1;
        if(y - radius < 0) exit(0);
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }



};