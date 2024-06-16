#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level3){}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
