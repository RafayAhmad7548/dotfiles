/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Count{
    int count;
public:

    Count() : count(0){}

    int operator++(){
        count++;
        return count;
    }
    int operator++(int){
        count++;
        return count-1;
    }
};

int main(){

    Count c1;


    return 0;
}