#ifndef PADDLE_H
#define PADDLE_H

#include "Ball.h"
class Paddle{
    const int height;

    int width;
    int x;
    int y;
    float *color;

public:

    Paddle(int width, int x, float *color); 
    Paddle(const Paddle& other);

    void draw();
    void checkCollision(Ball& ball);

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    Paddle& setWidth(int width);
    Paddle& setX(int x);
    ~Paddle();
};

#endif