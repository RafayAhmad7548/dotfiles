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

    ~Inventory(){
        delete[] products;
    }
    

};

int main(){

    // user interface to interact with classes and also take input
    Inventory inventory(10);
    cout<<"Enter 1 to add product"<<endl;
    cout<<"Enter 2 to remove product by id"<<endl;
    cout<<"Enter 3 to remove product by name"<<endl;
    cout<<"Enter 4 to remove product by id and quantity"<<endl;
    cout<<"Enter 5 to update quantity of product"<<endl;
    cout<<"Enter 6 to get product by id"<<endl;
    cout<<"Enter 7 to calculate inventory value"<<endl;
    cout<<"Enter 8 to display inventory"<<endl;
    cout<<"Enter 0 to exit"<<endl;
    int choice;
    int id, quantity;
    float price;
    char name[100];

    // swithc no curlies afte cases
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter id: ";
                cin>>id;
                cout<<"Enter name: ";
                cin>>name;
                cout<<"Enter price: ";
                cin>>price;
                cout<<"Enter quantity: ";
                cin>>quantity;
                inventory.addProduct(id, name, price, quantity);
            break;
            case 2:
                cout<<"Enter id: ";
                cin>>id;
                inventory.removeProduct(id);
            break;
            case 3:
                cout<<"Enter name: ";
                cin>>name;
                inventory.removeProduct(name);
            break;
            case 4:
                cout<<"Enter id: ";
                cin>>id;
                cout<<"Enter quantity: ";
                cin>>quantity;
                inventory.removeProduct(id, quantity);
            break;
            case 5:
                cout<<"Enter id: ";
                cin>>id;
                cout<<"Enter quantity change: ";
                cin>>quantity;
                inventory.updateQuantity(id, quantity);
            break;
            case 6:
                cout<<"Enter id: ";
                cin>>id;
                Product product = inventory.getProduct(id);
                cout<<"ID: "<<product.getId()<<endl;
                cout<<"Name: "<<product.getName()<<endl;
                cout<<"Price: "<<product.getPrice()<<endl;
                cout<<"Quantity: "<<product.getQuantity()<<endl;
            break;
            case 7:
                cout<<"Inventory value: "<<inventory.calculateInventoryValue()<<endl;
                break;
            case 8:
                inventory.display();
                break;
            case 0:
                return 0;
        }
    }

    return 0;
}