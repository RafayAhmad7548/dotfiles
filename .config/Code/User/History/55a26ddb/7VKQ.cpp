/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
#include <cstring>
using namespace std;

class Product{
    int id;
    char* name;
    float price;
    int quantity;

public:

    Product(int id, char* name, float price, int quantity) : id(id), price(price), quantity(quantity){
        int length = strlen(name);
        this->name = new char[length+1];
        strcpy(this->name, name);
    }



};

int main(){

    

    return 0;
}