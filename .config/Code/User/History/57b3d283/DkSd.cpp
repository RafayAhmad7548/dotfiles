/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class CustomerList{
    int* customerId;
    int size;
    int capacity;
public:
    CustomerList() : size(0), capacity(10){
        customerId = new int[capacity];
    } 
};

int main(){

    

    return 0;
}