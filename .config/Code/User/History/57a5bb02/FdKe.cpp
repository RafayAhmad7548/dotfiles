/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class SortedCatalog{
    int* arr;
    int size;
    int i;

    void increaseCapacity(){
        int* newArr = new int[size*2];
        for(int j=0;j<size;j++){
            newArr[j] = arr[j];
        }
        delete arr;
        arr = newArr;
        size *= 2;
    }

public:
    SortedCatalog() : size(10), i(0){
        arr = new int[size];
    }

    void addProduct(int sku){
        if(i == 0) arr[i] = sku;
        else{
            
        }
    }

    int findProduct(int sku) const{
        int left = 0;
        int right = i;
        int mid;
        while(left < right){
            mid = (left + right)/2;
            if(arr[mid] == sku) return mid;
            else if(arr[mid] < sku) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }

    void printCatalog() const{
        for(int j=0;j<i;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }


};



int main(){

    SortedCatalog catalog;

    catalog.addProduct(5);
    catalog.addProduct(3);
    catalog.addProduct(2);
    catalog.addProduct(10);

    catalog.printCatalog();


    return 0;
}