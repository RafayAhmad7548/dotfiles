/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class CustomerList{
    int* customerIds;
    int size;
    int capacity;

    void increaseCapacity(){
        int* newArr = new int[size*2];
        for(int j=0;j<size;j++){
            newArr[j] = customerIds[j];
        }
        delete[] customerIds;
        customerIds = newArr;
        size *= 2;
    }
public:
    CustomerList() : size(0), capacity(10){
        customerIds = new int[capacity];
    } 
    ~CustomerList(){
        delete[] customerIds;
    }

    void addCustomer(int customerId){
        if(size >= capacity) increaseCapacity();
        customerIds[size] = customerId;
        size++;
    }

    int findCustomer(int customerId){
        for(int i=0;i<size;i++){
            if(customerIds[i] == customerId) return i;
        }
        return -1;
    }

    bool removeCustomer(int customerId){
        bool removed = false;
        for(int i=0;i<size;i++){
            if(customerIds[i] == customerId){
                for(int j=i;j<size-1;j++){
                    customerIds[j] = customerIds[j+1];
                }
                removed = true;
                size--;
                break;
            }
        }
        return removed;
    }

    void printList(){
        for(int i=0;i<size;i++){
            cout<<customerIds[i]<<endl;
        }
    }

};

int main(){

    CustomerList list;
    list.addCustomer(1);
    list.addCustomer(2);
    list.addCustomer(3);
    list.addCustomer(4);

    list.printList();
    

    return 0;
}