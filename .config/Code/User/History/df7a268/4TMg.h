#ifndef BALL_H
#define BALL_H

#include "util.h"
class Ball{
    const int radius;

    int x;
    int y;
    float *color;

    int vX;
    int vY;

public:

    Ball(int x, int y, int radius, float *color); 

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

    int getRadius(){
        return radius;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getVX(){
        return vX;
    }
    int getVY(){
        return vY;
    }
    Ball& setVX(int vX){
        this->vX = vX;
        return *this;
    }
    Ball& setVY(int vY){
        this->vY = vY;
        return *this;
    }


};

#endif