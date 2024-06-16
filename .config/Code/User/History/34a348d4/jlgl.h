#include <string>
#include "GameLevel.h"
#include "Level1.cpp"
#include "Level2.cpp"
#include "Level3.cpp"

class BrickBreaker{

    GameLevel *level;
    int currentLevel;
    std::string gameState;

public:

    BrickBreaker();

    void nextLevel();
    std::string getGameState();
    GameLevel* getLevel();

};