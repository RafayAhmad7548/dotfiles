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

    Product() : id(0), price(0), quantity(0){
        name = nullptr;
    }
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

class Inventory{
    Product* products;
    int count;
    int size;

public:

    Inventory(int size) : size(size), count(0){
        products = new Product[size];
    }

    void addProduct(int id, char* name, float price, int quantity){
        if(count<size){
            products[count] = Product(id, name, price, quantity);
            count++;
        }
        else cout<<"Inventory is full"<<endl;
    }

    void addProdcut(Product* product){
        if(count<size){
            products[count] = *product;
            count++;
        }
        else cout<<"Inventory is full"<<endl;
    }

    void removeProduct(int id){
        for(int i=0;i<count;i++){
            if(products[i].getId() == id){
                for(int j=i;j<count-1;j++){
                    products[j] = products[j+1];
                }
                count--;
                break;
            }
        }
    }

    void removeProduct(char* name){
        for(int i=0;i<count;i++){
            if(strcmp(products[i].getName(), name)==0){
                for(int j=i;j<count-1;j++){
                    products[j] = products[j+1];
                }
                count--;
                break;
            }
        }
    }

    void removeProduct(int id, int count){
        for(int i=0;i<this->count;i++){
            if(products[i].getId() == id){
                products[i].setQuantity(products[i].getQuantity()-count);
                break;
            }
        }
    }

    void updateQuantity(int id, int quantityChange){
        for(int i=0;i<count;i++){
            if(products[i].getId() == id){
                products[i].setQuantity(products[i].getQuantity()+quantityChange);
                break;
            }
        }
    }

    Product& getProduct(int id){
        for(int i=0;i<count;i++){
            if(products[i].getId() == id){
                return products[i];
            }
        }
    }

    float calculateInventoryValue(){
        float total = 0;
        for(int i=0;i<count;i++) total += products[i].getPrice() * products[i].getQuantity();
        return total;
    }

    void display(){
        for(int i=0;i<count;i++){
            cout<<"ID: "<<products[i].getId()<<endl;
            cout<<"Name: "<<products[i].getName()<<endl;
            cout<<"Price: "<<products[i].getPrice()<<endl;
            cout<<"Quantity: "<<products[i].getQuantity()<<endl;
            cout<<endl;
        }
    }
    

};

int main(){

    

    return 0;
}