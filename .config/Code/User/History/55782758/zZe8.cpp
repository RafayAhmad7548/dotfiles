/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class IceCream{
    char *flavor;
    char *topping;
    char *servingType;
    bool isReady;
    double price;

public:
    IceCream(){}
    IceCream(char *flavor, char *topping, char *servingType, double price) : flavor(flavor), topping(topping), servingType(servingType), price(price), isReady(false){}
    IceCream(char *topping, double price) : flavor(nullptr), topping(topping), servingType(nullptr), price(price){}
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