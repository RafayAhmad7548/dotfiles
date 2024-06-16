#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level3){}

void BrickBreaker::nextLevel(){

}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
