#include "Food.h"
#include "util.h"

class RedFood : public Food{
    
    const int width = 20;
    const int height = 10;

public:

    RedFood(int x, int y) : Food(x, y, colors[RED]){}


};