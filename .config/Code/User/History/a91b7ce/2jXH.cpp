#include "Paddle.h"
#include "Ball.h"
#include "util.h"

Paddle::Paddle(int width, int x, float *color) : height(20), y(10), width(width), x(x), color(color){}
Paddle::Paddle(const Paddle& other) : height(other.height), y(other.y), width(other.width), x(other.x), color(other.color){}

void Paddle::draw(){
    DrawRectangle(x, y, width, height, color);
}

void Paddle::checkCollision(Ball& ball){
    if(ball.getY()-ball.getRadius() == y+height && ball.getX()-ball.getRadius() > x && ball.getX()+ball.getRadius() < x+width) ball.setVY(ball.getVY()*-1);
    if(ball.getY() <= y+height && ball.getX() >= x && ball.getX() < x+width) ball.setVX(ball.getVX()*-1);
    //TODO: game over screen
    if(ball.getY() < 0) exit(1); 
}

Paddle& Paddle::setX(int x){
    if(x < width/2) this->x = 0;
    else if(x > 1050 - width/2) this->x = 1050 - width;
    else this->x = x - width/2;
    return *this;
}
