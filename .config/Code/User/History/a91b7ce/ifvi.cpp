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
    int x, y;
    switch(rand()%3){
        case 0: x = 0; y = 5; break;
        case 1: x = 5; y = 5; break;
        case 2: x = 5/2 * sqrt(3); y = 5/2; break;
    }
    x *= ball.getVX()>0 ? -1 : 1;
    if(ball.getY() - ball.getRadius() <= y+height && ball.getX()-ball.getRadius() >= x && ball.getX()+ball.getRadius() < x+width) {ball.setVY(y); cout<<111;}
    if(ball.getY() <= y+height && ball.getX() >= x && ball.getX() < x+width) ball.setVX(x);
    //TODO: game over screen
    if(ball.getY() < 0) exit(1); 
}

Paddle& Paddle::setX(int x){
    if(x < 10 + width/2) this->x = 10;
    else if(x > 1010 - width/2) this->x = 1010 - width;
    else this->x = x - width/2;
    return *this;
}
