/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;


class ResizableArray{
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

    void decreaseCapacity(){
        int* newArr = new int[size/2];
        for(int j=0;j<size;j++){
            newArr[j] = arr[j];
        }
        delete arr;
        arr = newArr;
        size /= 2;
    }

public:
    ResizableArray() : size(1), i(0), arr(new int[size]){}

    void add(int value){
        if(i >= size) increaseCapacity();
        arr[i] = value;
        i++;
    }

    bool insert(int index, int value){
        if(index < 0 || index > size) return false;
        else{
            if(i >= size) increaseCapacity();
            for(int j=i;j>=index;j--){
                arr[j+1] = arr[j];
            }
            arr[index] = value;
        }
        return true;
    }

    bool remove(int index){
        if(index < 0 || index > size) return false;
        else{
            for(int j=index;j<i;j++){
                arr[j] = arr[j+1];
            }
            if(i < size/4) decreaseCapacity();
        }
        return true;
    }

    bool updateElement(int index, int value){
        if(index < 0 || index > size) return false;
    }
};


int main(){

    

    return 0;
}