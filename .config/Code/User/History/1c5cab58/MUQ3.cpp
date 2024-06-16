#include "GameLevel.h"
#include "util.h"
#include "GreenFood.cpp"
#include "PinkFood.cpp"
#include "BlueFood.cpp"
#include "RedFood.cpp"
#include "YellowFood.cpp"

GameLevel::GameLevel() : score(0), lives(2), paddle(Paddle(125, 10, 10, colors[GRAY])), paddle2(nullptr){
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
	DrawRectangle(0, 840, 1050, 30, colors[GRAY]);
    DrawString(10, 850, "Rafay Ahmad 23i-2526", colors[BLACK]);
    DrawString(300, 850, "Score: " + to_string(score), colors[BLACK]);
    DrawString(600, 850, "Lives: " + to_string(lives), colors[BLACK]);
    paddle.draw();
    if(paddle2 != nullptr) paddle2->draw();
    for(int i=0;i<3;i++) if(balls[i] != nullptr) balls[i]->draw();
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(bricks[i][j] != nullptr) bricks[i][j]->draw(i, j);
            if(food[i][j] != nullptr) food[i][j]->draw();
        }
    }
}

void GameLevel::checkBalls(int& lives){
    bool ballsLeft = false;
    for(int i=0;i<3;i++){
        if(balls[i] != nullptr) ballsLeft = true;
    }
    if(!ballsLeft){
        lives--;
        balls[0] = new Ball(-10, 50, 10, colors[RED]);
    }
    if(lives <= 0) exit(0);
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
                    score++;
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

void GameLevel::checkLevelEnd(){
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(bricks[i][j] != nullptr){
                
            }
        }
    }
}

int& GameLevel::getLives(){
    return lives;
}
Ball**& GameLevel::getBalls(){
    return balls;
}
Paddle& GameLevel::getPaddle(){
    return paddle;
}
Paddle* GameLevel::getPaddle2(){
    return nullptr;
}

GameLevel::~GameLevel(){
    for(int i=0;i<3;i++) if(balls[i] != nullptr){
        delete balls[i];
        balls[i] = nullptr;
    }
    delete[] balls;
    balls = nullptr;
    for(int i=0;i<25;i++){
        for(int j=0;j<15;j++){
            if(bricks[i][j] != nullptr){
                delete bricks[i][j];
                bricks[i][j] = nullptr;
            }
            if(food[i][j] != nullptr){
                delete food[i][j];
                food[i][j] = nullptr;
            }
        }
        delete[] bricks[i];
        bricks[i] = nullptr;
        delete[] food[i];
        food[i] = nullptr;
    }
    delete[] bricks;
    bricks = nullptr;
    delete[] food;
    food = nullptr;
    if(paddle2 != nullptr){
        delete paddle2;
        paddle2 = nullptr;
    }
}