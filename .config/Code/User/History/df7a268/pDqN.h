#ifndef BALL_H
#define BALL_H

class Ball{
    const int radius;

    int x;
    int y;
    float *color;

    int vX;
    int vY;

public:

    Ball(int x, int y, int radius, float *color);
    Ball(const Ball& other);

    void draw();
    void move();
    void checkBoundCollision();

    int getRadius();
    int getX();
    int getY();
    int getVX();
    int getVY();
    float* getColor();
    Ball& setVX(int vX);
    Ball& setVY(int vY);

    ~Ball();
};

#endif