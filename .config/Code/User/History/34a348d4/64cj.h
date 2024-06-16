#include <string>
#include "GameLevel.h"
#include "Level1.cpp"
#include "Level2.cpp"
#include "Level3.cpp"

using namespace std;


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