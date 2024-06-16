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

bool Brick::checkCollision(Ball& ball){
    bool collided = false;
    if(ball.getX() >= x && ball.getX() < x+width){
        if(ball.getY() >= y && ball.getY() <= y+4){
            ball.setVY(ball.getVY()>0 ? ball.getVY()*-1 : ball.getVY());
            ball.setY(ball.getY()/10*10);
            collided = true;
        }
        if(ball.getY() <= y+height && ball.getY() >= y+height-4){
            ball.setVY(ball.getVY()>0 ? ball.getVY() : ball.getVY()*-1);
            ball.setY(ball.getY()/10*10);
            collided = true;
        }
    }
    if(ball.getY() >= y && ball.getY() < y+height){
        if(ball.getX() >= x && ball.getX() <= x+4){
            ball.setVX(ball.getVX()>0 ? ball.getVX()*-1 : ball.getVX());
            ball.setX(ball.getX()/10*10);
            collided = true;
        }
        if(ball.getX() <= x+width && ball.getX() >= x+width-4){
            ball.setVX(ball.getVX()>0 ? ball.getVX() : ball.getVX()*-1);
            ball.setX(ball.getX()/10*10);
            collided = true;
        }
    }
    if(collided){
        strength--;
        if(strength == 2){
            if(color == colors[BLUE]){
                food = new BlueFood(x+width/2, y);
                ball.setColor(colors[BLUE]);   
            }
            else if(color == colors[RED]){
                food = new RedFood(x+width/2, y);
                ball.setColor(colors[RED]);
            }
            color = rand()%2 ? colors[PINK] : colors[YELLOW];
        }
        else if(strength == 1){
            if(color == colors[PINK]){
                food = new PinkFood(x+width/2, y);
                ball.setColor(colors[PINK]);
            }
            else if(color == colors[YELLOW]){
                food = new YellowFood(x+width/2, y);
                ball.setColor(colors[YELLOW]);
            }
            color = colors[GREEN];
        }
        else{
            food = new GreenFood(x+width/2, y);
            ball.setColor(colors[GREEN]);
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