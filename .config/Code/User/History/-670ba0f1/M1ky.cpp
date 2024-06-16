#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level3){}

void BrickBreaker::nextLevel(){
    currentLevel++;
    if(level != nullptr) delete level;

}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
