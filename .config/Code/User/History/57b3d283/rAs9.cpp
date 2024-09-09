/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class CustomerList{
    int* customerIds;
    int size;
    int capacity;
public:
    CustomerList() : size(0), capacity(10){
        customerIds = new int[capacity];
    } 
    ~CustomerList(){
        delete[] customerIds;
    }

    void addCustomer(int customerId){
        if(size >= capacity) increaseCapacity();
        customerIds[size] = customerId;
        size++;
    }

};

int main(){

    

    return 0;
}