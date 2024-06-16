/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Customer{
    string name;
    string address;

public:

    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
};

class Product{
    string name;
    double price;

public:

    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
};

class Order{
    Customer customer;
    Product *products;
    int *qtys;
    int noOfProducts;

public:

    Order(Customer customer, int noOfProducts) : customer(customer), noOfProducts(noOfProducts){
        products = new Product[noOfProducts];
        qtys = new int[noOfProducts];
    }

    void addItem(Product product, int qty){
        
    }





};


int main(){

    

    return 0;
}