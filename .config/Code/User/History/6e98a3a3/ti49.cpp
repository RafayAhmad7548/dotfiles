#include "Ball.h"
#include "util.h"

Ball::Ball(int x, int y, int radius, float *color) : x(rand()%1050), y(y), radius(radius), color(color), vX(5), vY(5){}
Ball::Ball(const Ball& other) : x(other.x), y(other.y), radius(other.radius), vX(other.vX), vY(other.vY){
    // color = new float[3];
    color = other.color;
}

void Ball::draw(){
    DrawCircle(x, y, radius, color);
}

void Ball::move(){
    x += vX;
    y += vY;
}

void Ball::checkBoundCollision(){
    if(x - radius <= 0 || x + radius >= 1050) vX *= -1;
    if(y + radius >= 840) vY *= -1;
}

int Ball::getRadius(){
    return radius;
}
int Ball::getX(){
    return x;
}
int Ball::getY(){
    return y;
}
int Ball::getVX(){
    return vX;
}
int Ball::getVY(){
    return vY;
}
Ball& Ball::setVX(int vX){
    this->vX = vX;
    return *this;
}
Ball& Ball::setVY(int vY){
    this->vY = vY;
    return *this;
}