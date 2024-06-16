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

    void draw(){
        DrawRectangle(x, y, width, height, color);
    }

    Paddle& setX(int x){
        if(x < 10 + width/2) this->x = 10;
        else if(x > 1010 - width/2) this->x = 1010 - width;
        else this->x = x - width/2;
        return *this;
    }

    void checkCollision(Ball& ball){
        if(ball.getY() - ball.getRadius() < y+height && ball.getX()+ball.getRadius() > x && ball.getX()-ball.getRadius() < x+width){
            ball.setVY(ball.getVY()*-1);
        }
    }

};

#endif