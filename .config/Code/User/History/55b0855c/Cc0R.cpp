/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
using namespace std;

class Library{
    char* bookTtile;
    char* author;
    int bookID;
    int quantity;
    float price;
    static int totalBooks;

public:

    // getter
    char* getBookTitle(){
        return bookTtile;
    }
    char* getAuthor(){
        return author;
    }
    int getBookID(){
        return bookID;
    }
    int getQuantity(){
        return quantity;
    }
    float getPrice(){
        return price;
    }
    



};

int main(){

    

    return 0;
}