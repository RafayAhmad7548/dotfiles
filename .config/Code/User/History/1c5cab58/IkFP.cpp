#include "GameLevel.h"
#include "util.h"
#include "GreenFood.cpp"
#include "PinkFood.cpp"
#include "BlueFood.cpp"
#include "RedFood.cpp"
#include "YellowFood.cpp"

GameLevel::GameLevel() : score(0), lives(2), paddle(Paddle(125, 10, colors[GRAY])){
    bricks = new Brick**[25];
    food = new Food**[25];

    balls = new Ball*[3];
    balls[0] = new Ball(-10, 50, 10, colors[RED]);
    for(int i=1;i<3;i++) balls[i] = nullptr;

    for(int i=0;i<25;i++){
        bricks[i] = new Brick*[15];
        food[i] = new Food*[15];
        for(int j=0;j<15;j++){
            bricks[i][j] = nullptr;
            food[i][j] = nullptr;
        }
    }
}

void GameLevel::draw(){
    paddle.draw();
    for(int i=0;i<3;i++) if(balls[i] != nullptr) balls[i]->draw();
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(bricks[i][j] != nullptr) bricks[i][j]->draw(i, j);
            if(food[i][j] != nullptr) food[i][j]->draw();
        }
    }
}

void GameLevel::checkBrickCollision(){
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(bricks[i][j] != nullptr){
                bool broken = false;
                for(int k=0;k<3;k++) if(balls[k] != nullptr) broken = bricks[i][j]->checkCollision(*balls[k]);
                food[i][j] = bricks[i][j]->getFood();
                if(broken){
                    delete bricks[i][j];
                    bricks[i][j] = nullptr;
                }
            }
            
        }
    }
}

void GameLevel::moveFood(){
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(food[i][j] != nullptr) food[i][j]->fall();
        }
    }
}

void GameLevel::checkFoodCollision(){
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(food[i][j] != nullptr){
                if(food[i][j]->getX() > paddle.getX() && food[i][j]->getX() < paddle.getX()+paddle.getWidth() && food[i][j]->getY() < paddle.getY()+paddle.getHeight() && food[i][j]->getY() > 0){
                    food[i][j]->activatePowerup(paddle, balls);
                }
            } 
        }
    }
}

Ball**& GameLevel::getBalls(){
    return balls;
}
Paddle& GameLevel::getPaddle(){
    return paddle;
}

GameLevel::~GameLevel(){
    for(int i=0;i<3;i++) if(balls[i] != nullptr) delete balls[i];
    delete[] balls;
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(bricks[i][j] != nullptr) delete bricks[i][j];
            if(food[i][j] != nullptr) delete food[i][j];
        }
        delete[] bricks[i];
        delete[] food[i];
    }
    delete[] bricks;
    delete[] food;
}