/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

int strL(char *s){
    int length = 0;
    while(s[length] != '\0') length++;
    return length;
}

class IceCream{
    char *flavor;
    char *topping;
    char *servingType;
    bool isReady;
    double price;

public:
    IceCream(){}
    IceCream(char *flavor, char *topping, char *servingType, double price) : price(price), isReady(false){
        int length = strL(flavor);
        this->flavor = new char[length+1];
        for(int i=0;i<length;i++) this->flavor[i] = flavor[i];
        this->flavor[length] = '\0';

        length = strL(topping);
        this->topping = new char[length+1];
        for(int i=0;i<length;i++) this->topping[i] = topping[i];
        this->topping[length] = '\0';

        length = strL(servingType);
        this->servingType = new char[length+1];
        for(int i=0;i<length;i++) this->servingType[i] = servingType[i];
        this->servingType[length] = '\0';
    }
    IceCream(char *topping, double price) : flavor(nullptr), servingType(nullptr), isReady(false), price(price){
        int length = strL(topping);
        this->topping = new char[length+1];
        for(int i=0;i<length;i++) this->topping[i] = topping[i];
        this->topping[length] = '\0';
    }
    IceCream(const IceCream &iceCream) : isReady(iceCream.isReady), price(iceCream.price){
        int length = strL(flavor);
        flavor = new char[length+1];
        for(int i=0;i<length;i++) flavor[i] = iceCream.flavor[i];
        flavor[length] = '\0';

        length = strL(topping);
        topping = new char[length+1];
        for(int i=0;i<length;i++) topping[i] = iceCream.topping[i];
        topping[length] = '\0';

        length = strL(servingType);
        servingType = new char[length+1];
        for(int i=0;i<length;i++) servingType[i] = iceCream.servingType[i];
        servingType[length] = '\0';
    }
    ~IceCream(){
        delete[] flavor;
        delete[] topping;
        delete[] servingType;
    }

    void setFlavor(char *flavor){
        int length = strL(flavor);
        this->flavor = new char[length+1];
        for(int i=0;i<length;i++) this->flavor[i] = flavor[i];
        this->flavor[length] = '\0';
    }
    void setTopping(char *topping){
        int length = strL(topping);
        this->topping = new char[length+1];
        for(int i=0;i<length;i++) this->topping[i] = topping[i];
        this->topping[length] = '\0';
    }
    void setServingType(char *servingType){
        int length = strL(servingType);
        this->servingType = new char[length+1];
        for(int i=0;i<length;i++) this->servingType[i] = servingType[i];
        this->servingType[length] = '\0';
    }
    void setPrice(double price){
        this->price = price;
    }

    char* getFlavor(){
        return flavor;
    }
    char* getTopping(){
        return topping;
    }
    char* getServingType(){
        return servingType;
    }
    double getPrice(){
        return price;
    }

    void makeIceCream(){
        if(topping != nullptr) isReady = true;
    }
    bool checkStatus(){
        return isReady;
    }

};

int main(){

    string flavor, topping, servingType;

    cout<<"Enter the flavor of ice cream: ";
    getline(cin, flavor);
    cout<<"Enter the topping of ice cream: ";
    getline(cin, topping);
    cout<<"Enter the serving type of ice cream: ";
    getline(cin, servingType);
    double price;
    cout<<"Enter the price of ice cream: ";
    cin>>price;

    IceCream iceCream1((char*)flavor.c_str(), (char*)topping.c_str(), (char*)servingType.c_str(), price);
    iceCream1.makeIceCream();
    cout<<"Ice Cream 1 is ready: "<<iceCream1.checkStatus()<<endl;

    IceCream iceCream2((char*)topping.c_str(), price);
    iceCream2.makeIceCream();
    cout<<"Ice Cream 2 is ready: "<<iceCream2.checkStatus()<<endl;

    IceCream iceCream3 = iceCream1;
    cout<<"Ice Cream 3 is ready: "<<iceCream3.checkStatus()<<endl;
    

    return 0;
}