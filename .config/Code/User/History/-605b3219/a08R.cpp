#include "Brick.h"
#include "util.h"
#include "GreenFood.cpp"
#include "PinkFood.cpp"
#include "BlueFood.cpp"
#include "RedFood.cpp"
#include "YellowFood.cpp"

Brick::Brick(){
    switch(rand()%5){
        case 0: color = colors[GREEN]; strength = 1; break;
        case 1: color = colors[PINK]; strength = 2; break;
        case 2: color = colors[BLUE]; strength = 3; break;
        case 3: color = colors[RED]; strength = 3; break;
        case 4: color = colors[YELLOW]; strength = 2; break;
    }
}

void Brick::draw(int row, int col){
    x = col*width;
    y = 340 + row*height;
    DrawRectangle(x, y, width, height, color);
}

// return 0 if didnt collide, 1 if brick broken, 2 if collison but not broken
int Brick::checkCollision(Ball& ball){
    bool collided = false;
    if(ball.getX() >= x && ball.getX() < x+width){
        if(ball.getY() == y){
            ball.setVY(-5);
            collided = true;
        }
        if(ball.getY() == y+height){
            ball.setVY(5);
            collided = true;
        }
    }
    if(ball.getY() >= y && ball.getY() < y+height){
        if(ball.getX() == x ){
            ball.setVX(-5);
            collided = true;
        }
        if(ball.getX() == x+width){
            ball.setVX(5);
            collided = true;
        }
    }
    if(collided){
        if(food != nullptr){
            delete food;
            food = nullptr;
        }
        strength--;
        if(strength == 2){
            if(color == colors[BLUE]) food = new BlueFood(x, y);
            else if(color == colors[RED]) food = new RedFood(x, y);
            color = rand()%2 ? colors[PINK] : colors[YELLOW];
        }
        else if(strength == 1){
            if(color == colors[PINK]) food = new PinkFood(x, y);
            else if(color == colors[YELLOW]) food = new YellowFood(x, y);
            color = colors[GREEN];
        }
        else{
            food = new GreenFood(x, y);
            return true;
        }
    }
    return false;
}

int Brick::getX(){
    return x;
}
int Brick::getY(){
    return y;
}
float* Brick::getColor(){
    return color;
}
Food* Brick::getFood(){
    return food;
}

Brick::~Brick(){}