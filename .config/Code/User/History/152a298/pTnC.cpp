#include "Food.h"
#include "util.h"

class PinkFood : public Food{

    int dimension;
    
public:

    PinkFood(int x, int y, int dimension) : dimension(dimension), Food(x, y, colors[PINK]){}




};