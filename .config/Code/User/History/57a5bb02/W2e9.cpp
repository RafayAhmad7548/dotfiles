/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class SortedCatalog{
    int* arr;
    int size;
    int i;

    void increaseCapacity(){
        int* newArr = new int[size*2];
        for(int j=0;j<size;j++){
            newArr[j] = arr[j];
        }
        delete arr;
        arr = newArr;
        size *= 2;
    }

public:
    SortedCatalog() : size(1), i(0), arr(new int[size]){}
};



int main(){

    

    return 0;
}