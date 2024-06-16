#include "BrickBreaker.h"
#include <string>
BrickBreaker::BrickBreaker() : currentLevel(1), gameState("playing"), level(new Level2){}

void BrickBreaker::nextLevel(){
    if(currentLevel<3){
        currentLevel++;
        if(level != nullptr) delete level;
        switch(currentLevel){
            case 2: level = new Level2; break;
            case 3: level = new Level3; break;
        }
    }
}
std::string BrickBreaker::getGameState(){
    return gameState;
}
GameLevel* BrickBreaker::getLevel(){
    return level;
}

BrickBreaker& BrickBreaker::setGameState(std::string gameState){
    this->gameState = gameState;
    return *this;
}
