#include "BrickBreaker.h"

BrickBreaker::BrickBreaker() : currentLevel(1), level(new Level3){}

void BrickBreaker::nextLevel(){
    currentLevel++;
    if(level != nullptr) delete level;
    switch(currentLevel){
        case 2: level = new Level2;
    }

}

GameLevel* BrickBreaker::getLevel(){
    return level;
}
