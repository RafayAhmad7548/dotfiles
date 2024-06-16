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
    struct OrderItem{
        Product product;
        int qty;
    };
    OrderItem *items;
    int noOfProducts;
public:

    Order(Customer customer) : customer(customer), noOfProducts(0){
        items = new OrderItem[1];
    }
    ~Order(){
        delete[] items;
    }

    void addItem(Product product, int qty){
        
        Product *tmpP = new Product[noOfProducts+1];
        int *tmpQ = new int[noOfProducts+1];

        for(int i=0;i<noOfProducts;i++){
            tmpP[i] = products[i];
            tmpQ[i] = qtys[i];
        }

        tmpP[noOfProducts] = product;
        tmpQ[noOfProducts] = qty;

        delete[] products;
        delete[] qtys;




        noOfProducts++;
    }

    void displayOrder(){
        
    }







};


int main(){

    

    return 0;
}