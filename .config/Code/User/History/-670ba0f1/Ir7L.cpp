#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level1){}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
