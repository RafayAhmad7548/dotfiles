#include "Paddle.h"
#include "Ball.h"
#include "util.h"

Paddle::Paddle(int width, int x, int y, float *color) : height(20), y(y), width(width), x(x), color(color){}
Paddle::Paddle(const Paddle& other) : height(other.height), y(other.y), width(other.width), x(other.x), color(other.color){}

void Paddle::draw(){
    DrawRectangle(x, y, width, height, color);
}

void Paddle::checkCollision(Ball& ball){
    if(ball.getX() >= x && ball.getX() < x+width){
        if(ball.getY() >= y && ball.getY() <= y+4){
            ball.setVY(ball.getVY()>0 ? ball.getVY()*-1 : ball.getVY());
            ball.setY(ball.getY()/10*10);
            color = ball.getColor();
        }
        if(ball.getY() <= y+height && ball.getY() >= y+height-4){
            ball.setVY(ball.getVY()>0 ? ball.getVY() : ball.getVY()*-1);
            ball.setY(ball.getY()/10*10);
            color = ball.getColor();
        }
    }
    if(ball.getY() >= y && ball.getY() < y+height){
        if(ball.getX() >= x && ball.getX() <= x+4){
            ball.setVX(ball.getVX()>0 ? ball.getVX()*-1 : ball.getVX());
            ball.setX(ball.getX()/10*10);
            color = ball.getColor();
        }
        if(ball.getX() <= x+width && ball.getX() >= x+width-4){
            ball.setVX(ball.getVX()>0 ? ball.getVX() : ball.getVX()*-1);
            ball.setX(ball.getX()/10*10);
            color = ball.getColor();
        }
    }
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
