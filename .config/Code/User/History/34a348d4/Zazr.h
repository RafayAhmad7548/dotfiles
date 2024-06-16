#include "GameLevel.h"
#include "Level1.cpp"


class BrickBreaker{

    GameLevel *level;
    int currentLevel;

public:

    BrickBreaker() : currentLevel(1){
        level = new Level1;
    }




};