/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

int length(char *s){
    int length = 0;
    while(s[i] != '\0') length++;
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
        int length = 0;
        while(flavor[length] != '\0') length++;
        this->flavor = new char[length];
        for(int i=0;i<length;i++) this->flavor[i] = flavor[i];
        this->flavor[length] = '\0';

        length = 0;
        while(topping[length] != '\0') length++;
        for(int i=0;i<length;i++) this->topping[i] = topping[i];
        this->topping[length] = '\0';

        length = 0;
        while(servingType[length] != '\0') length++;
        for(int i=0;i<length;i++) this->servingType[i] = servingType[i];
        this->servingType[length] = '\0';
    }
    IceCream(char *topping, double price) : flavor(nullptr), topping(topping), servingType(nullptr), isReady(false), price(price){}
    IceCream(const IceCream &iceCream) : isReady(iceCream.isReady), price(iceCream.price){
        int length = 0;
        while(iceCream.flavor[length] != '\0') length++;
        flavor = new char[length];
        for(int i=0;i<length;i++) flavor[i] = iceCream.flavor[i];
        flavor[length] = '\0';

        length = 0;
        while(iceCream.topping[length] != '\0') length++;
        for(int i=0;i<length;i++) topping[i] = iceCream.topping[i];
        topping[length] = '\0';

        length = 0;
        while(iceCream.servingType[length] != '\0') length++;
        for(int i=0;i<length;i++) servingType[i] = iceCream.servingType[i];
        servingType[length] = '\0';
    }


};

int main(){


    return 0;
}