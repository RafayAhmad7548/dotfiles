#include "Paddle.h"
#include "Ball.h"
#include "util.h"

Paddle::Paddle(int width, int x, int y, float *color) : height(20), y(y), width(width), x(x), color(color){}
Paddle::Paddle(const Paddle& other) : height(other.height), y(other.y), width(other.width), x(other.x), color(other.color){}

void Paddle::draw(){
    DrawRectangle(x, y, width, height, color);
}

void Paddle::checkCollision(Ball& ball){
    //TODO: Redo Collisoin


    if(ball.getX() >= x && ball.getX() <= x+width){
        if(ball.getY()-ball.getRadius() >= y && ball.getY() <= y+4){
            
        }
    }


    // if(ball.getY()-ball.getRadius() == y+height && ball.getX()-ball.getRadius() > x && ball.getX()+ball.getRadius() < x+width){
    //     ball.setVY(ball.getVY()*-1);
    //     color = ball.getColor()
    // }
    // if(ball.getY() <= y+height && ball.getX() >= x && ball.getX() < x+width) ball.setVX(ball.getVX()*-1);
    // //TODO: game over screen
    // if(ball.getY() < 0) ball.setVY(ball.getVY()*-1);
}

int Paddle::getX(){
    return x;
}
int Paddle::getY(){
    return y;
}
int Paddle::getWidth(){
    return width;
}
int Paddle::getHeight(){
    return height;
}

Paddle& Paddle::setWidth(int width){
    this->width = width;
    return *this;
}
Paddle& Paddle::setX(int x){
    // if(x < width/2) this->x = 0;
    // else if(x > 1050 - width/2) this->x = 1050 - width;
    // else this->x = x - width/2;
    this->x = x;
    return *this;
}

Paddle::~Paddle(){}
