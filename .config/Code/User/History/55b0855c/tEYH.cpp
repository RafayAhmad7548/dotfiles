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
    // setter
    void setBookTitle(char* title){
        bookTtile = title;
    }
    void setAuthor(char* authorName){
        author = authorName;
    }
    void setBookID(int id){
        bookID = id;
    }
    void setQuantity(int q){
        quantity = q;
    }
    void setPrice(float p){
        price = p;
    }

    static void setTotalBooks(int totalBooks){
        Library::totalBooks = totalBooks;
    }
    static int getTotalBooks(){
        return Library::totalBooks;
    }

    void calcTotalPrice(){
        cout<<"Total Price: "<<this->price * this->quantity<<endl;
    }

};

Library getBookAt(Library books[], int index){
    return books[index];
}

void addBook(Library books[], Library book){
    books[Library::getTotalBooks()] = book;
    Library::setTotalBooks(Library::getTotalBooks() + 1);
}

void removeBook(Library books[], int bookID){
    for(int i = 0; i < Library::getTotalBooks(); i++){
        if(books[i].getBookID() == bookID){
            for(int j = i; j < Library::getTotalBooks() - 1; j++){
                books[j] = books[j + 1];
            }
            Library::setTotalBooks(Library::getTotalBooks() - 1);
            break;
        }
    }
}



int main(){

    

    return 0;
}