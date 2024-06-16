#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level1){}

void BrickBreaker::nextLevel(){
    currentLevel++;
    if(level != nullptr) delete level;
    switch(currentLevel){
        case 2: level = new Level2; break;
        case 3: level = new Level3; break;
    }
}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
