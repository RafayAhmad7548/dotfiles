#include "GameLevel.h"
#include "Level1.cpp"
#include "Level2.cpp"
#include "Level3.cpp"


class BrickBreaker{

    GameLevel *level;
    int currentLevel;
    string gameState;

public:

    BrickBreaker();

    void nextLevel();
    string getGameState();
    GameLevel* getLevel();


};