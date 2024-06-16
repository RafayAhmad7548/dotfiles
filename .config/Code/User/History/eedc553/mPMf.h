#ifndef PADDLE_H
#define PADDLE_H

class Paddle{
    const int height;
    const int y;

    int width;
    int x;
    float *color;

public:

    Paddle(int width, int x, float *color); 

    void draw();
    void checkCollision(Ball& ball);

    Paddle& setX(int x);
};

#endif