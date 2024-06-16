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

    Order(Customer customer) : customer(customer), noOfProducts(0){}
    ~Order(){
        delete[] products;
        delete[] qtys;
    }

    void addItem(Product product, int qty){
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