#include "Ball.h"
#include "util.h"

Ball::Ball(int x, int y, int radius, float *color) : y(y), radius(radius), color(color), vX(5), vY(5){
    static bool seeded = false;
    if(!seeded){
        srand(time(0));
        seeded = true;
    }
    if(x == -10) this->x = (rand()%104 + 1) * 10;
    else this->x = x;
}
Ball::Ball(const Ball& other) : x(other.x), y(other.y), radius(other.radius), vX(other.vX), vY(other.vY), color(other.color){}

void Ball::draw(){
    DrawCircle(x, y, radius, color);
}

void Ball::move(){
    x += vX;
    y += vY;
}

void Ball::checkBoundCollision(int& lives, int currentLevel){
    if(x - radius <= 0 || x + radius >= 1050) vX *= -1;
    
    if(y + radius >= 840) vY = vY<0 ? vY : vY*-1;
    if(y - radius <= 0) vY = vY<0 ? vY*-1 : vY;
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
float* Ball::getColor(){
    return color;
}
Ball& Ball::setColor(float *color){
    this->color = color;
    return *this;
}
Ball& Ball::setX(int x){
    this->x = x;
    return *this;
}
Ball& Ball::setY(int y){
    this->y = y;
    return *this;
}
Ball& Ball::setVX(int vX){
    this->vX = vX;
    return *this;
}
Ball& Ball::setVY(int vY){
    this->vY = vY;
    return *this;
}

Ball::~Ball(){}
