#include "Paddle.h"
#include "Ball.h"
#include "util.h"

Paddle::Paddle(int width, int x, float *color) : height(20), y(10), width(width), x(x), color(color){}
Paddle::Paddle(const Paddle& other) : height(other.height), y(other.y), width(other.width), x(other.x){
    // color = new float[3];
    color = other.color;
}

void Paddle::draw(){
    DrawRectangle(x, y, width, height, color);
}

void Paddle::checkCollision(Ball& ball){
    // y = 5, 5, 2.5
    // x = 0, 5, 5/2 sqrt3
    // int vx, vy;
    // switch(rand()%3){
    //     case 0: vx = 0; vy = 5; break;
    //     case 1: vx = 5; vy = 5; break;
    //     case 2: vx = 5/2 * sqrt(3); vy = 5/2; break;
    // }
    // vx *= ball.getVX()>0 ? -1 : 1;
    if(ball.getY() - ball.getRadius() <= y+height && ball.getX()-ball.getRadius() >= x && ball.getX()+ball.getRadius() < x+width) ball.setVY(ball.getVY()*-1);
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