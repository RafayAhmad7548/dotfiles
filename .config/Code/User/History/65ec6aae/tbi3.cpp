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

    Customer(string name, string address) : name(name), address(address){}

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

    Product(){}
    Product(string name, double price) : name(name), price(price){}

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

    Order(Customer customer, Product product, int qty) : customer(customer), noOfProducts(1){
        items = new OrderItem[1]{product, qty};
    }
    ~Order(){
        delete[] items;
    }

    void addItem(Product product, int qty){
        
        OrderItem *tmp = new OrderItem[noOfProducts+1];
        for(int i=0;i<noOfProducts;i++) tmp[i] = items[i];
        tmp[noOfProducts] = {product, qty};

        delete[] items;
        items = tmp;

        noOfProducts++;
    }

    void displayOrder(){
        cout<<"Name: "<<customer.getName()<<endl;       
        cout<<"Address: "<<customer.getAddress()<<endl;
        for(int i=0;i<noOfProducts;i++){
            cout<<"product name: "<<items[i].product.getName()<<"\t";
            cout<<"product price: "<<items[i].product.getPrice()<<endl;
        }
    }

};


int main(){

    Order order(Customer("ammar", "1233"), Product("milk", 50), 10);

    order.addItem(Product("eggs", 40), 10);

    order.displayOrder();




    return 0;
}