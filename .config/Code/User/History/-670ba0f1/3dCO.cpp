#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level2){}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
