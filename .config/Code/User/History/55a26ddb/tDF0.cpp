/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
#include <cstring>
using namespace std;

class InventoryManagement{
    int id;
    char* name;
    float price;
    int quantity;

public:

    // Constructor using member initializer list and lenstr
    InventoryManagement(int id, char* name, float price, int quantity) : id(id), price(price), quantity(quantity){
        int length = lenstr(name);
        this->name = new char[length+1];
        for(int i=0;i<length;i++) this->name[i] = name[i];
        this->name[length] = '\0';
    }



};

int main(){

    

    return 0;
}