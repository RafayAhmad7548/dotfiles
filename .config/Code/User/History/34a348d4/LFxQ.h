#include "GameLevel.h"
#include "Level1.cpp"
#include "Level2.cpp"


class BrickBreaker{

    GameLevel *level;
    int currentLevel;

public:

    BrickBreaker();

    GameLevel* getLevel();


};