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

    Order(Customer customer) : customer(customer), noOfProducts(0), products(nullptr), qtys(nullptr){}
    ~Order(){
        if(products != nullptr){
            delete[] products;
            products = nullptr;
        }
        if(qtys != nullptr){
            delete[] qtys;
            qtys = nullptr;
        }
    }

    void addItem(Product product, int qty){
        noOfProducts++;
        products = new Product[noOfProducts];



        products[noOfProducts] = product;
        qtys[noOfProducts] = qty;
        noOfProducts++;
    }

    void displayOrder(){
        
    }







};


int main(){

    

    return 0;
}