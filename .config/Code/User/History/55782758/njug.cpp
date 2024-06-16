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
    double price;

    cout<<"Enter details for Ice Cream 1:\n";
    cout<<"Flavor: ";
    getline(cin, flavor);
    cout<<"Topping: ";
    getline(cin, topping);
    cout<<"Serving Type: ";
    getline(cin, servingType);
    cout<<"Price: ";
    cin>>price;

    IceCream iceCream1(flavor, topping, servingType, price);

    cout<<"\nEnter details for Ice Cream 2:\n";
    cout<<"Topping: ";
    getline(cin, topping);
    cout<<"Price: ";
    cin>>price;

    IceCream iceCream2(topping, price);

    IceCream iceCream3(iceCream1);

    cout<<"\nIce Cream 1: "<<iceCream1.getFlavor()<< " " <<iceCream1.getTopping()<< " " <<iceCream1.getServingType()<< " " <<iceCream1.getPrice()<<endl;
    cout<<"Ice Cream 2: "<<iceCream2.getTopping()<< " " <<iceCream2.getPrice()<<endl;
    cout<<"Ice Cream 3: "<<iceCream3.getFlavor()<< " " <<iceCream3.getTopping()<< " " <<iceCream3.getServingType()<< " " <<iceCream3.getPrice()<<endl;

    iceCream1.makeIceCream();
    iceCream2.makeIceCream();
    iceCream3.makeIceCream();

    cout<<"\nIce Cream 1 is ready: "<<(iceCream1.checkStatus() ? "Yes" : "No")<<endl;
    cout<<"Ice Cream 2 is ready: "<<(iceCream2.checkStatus() ? "Yes" : "No")<<endl;
    cout<<"Ice Cream 3 is ready: "<<(iceCream3.checkStatus() ? "Yes" : "No")<<endl;

    return 0;
}