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

    // Constructor using member initializer list and lenstr and srccpy functions
    InventoryManagement(int id, char* name, float price, int quantity) : id(id), price(price), quantity(quantity){
        int length = strlen(name);
        this->name = new char[length+1];
        strcpy(this->name, name);
    }



};

int main(){

    

    return 0;
}