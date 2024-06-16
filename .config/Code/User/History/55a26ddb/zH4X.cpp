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

    ~Product(){
        delete[] name;
    }

    int getId(){
        return id;
    }
    char* getName(){
        return name;
    }
    float getPrice(){
        return price;
    }
    int getQuantity(){
        return quantity;
    }

    void setId(int id){
        this->id = id;
    }
    void setName(char* name){
        int length = strlen(name);
        this->name = new char[length+1];
        strcpy(this->name, name);
    }
    void setPrice(float price){
        this->price = price;
    }
    void setQuantity(int quantity){
        this->quantity = quantity;
    }



};

int main(){

    

    return 0;
}