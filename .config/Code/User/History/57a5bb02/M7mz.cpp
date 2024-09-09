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
    SortedCatalog() : size(10), i(0), arr(new int[size]){}

    void add(int sku){
        if(i == 0) arr[i] = sku;
        else{
            for(int j=0;j<i;j++){
                if(arr[j] > sku){
                    for(int k=i;k>=j;k--){
                        arr[k] = arr[k+1];
                    }
                    arr[j] = sku;       
                    break;
                }
            }
        }
    }

};



int main(){

    

    return 0;
}