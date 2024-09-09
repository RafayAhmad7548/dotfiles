#include <iostream>
using namespace std;

//class template 
template <typename T>
class List{
private:
    T* list;           // Dynamic array to store the list elements
    int capacity;      // Maximum capacity of the list
    int length;        // Current number of elements in the list

    void resize(){
        // Resize the array to double its current size
        T* newList = new T[capacity * 2];
        for(int i=0;i<length;i++){
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
        capacity *= 2;
    }

public:
    // Constructor to initialize the list with a fixed capacity
    List(int initialSize = 100){
        capacity = initialSize;
        list = new T[capacity];
        length = 0;
    }

    // Destructor to free the dynamically allocated memory
    ~List(){
        delete[] list;
    }

    // Insert an element at a specific position (0-based index)
    void insert(int position, T value){
        if(length >= capacity) resize();

        for(int i=length;i>=position;i--){
            list[i+1] = list[i];
        }
        list[position] = value;
        length++;
    }

    // Delete an element by its value (first occurrence)
    bool deleteByValue(T value){

    }

    // Delete an element by its position (0-based index)
    bool deleteByPosition(int position){
        if(position > length) return false;
        else{
            for(int i=position;i<length;i++){
                list[i] = list[i+1];
            }
            length--;
        }
        return true;
    }

    // Search for an element by its value, return the position if found, otherwise -1
    int search(T value){

    }

    // Access an element by its position (0-based index)
    T access(int position){
        
         // write code 
         
    }

    // Return the current number of elements in the list
    int size(){
       
        // write code 
    }

    // Check if the list is empty
    bool isEmpty(){
       
        // write code 
    }

    // Display the elements of the list
    void display(){
       
        // write code 
    }
};


int main() {
    
    // write code to test functionalities 
    
    return 0;
}

