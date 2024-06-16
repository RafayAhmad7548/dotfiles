/*
Rafay Ahmad
23I-2526
*/
#include <iostream>
#include <cstring>
using namespace std;

class Library{
    char* bookTitle;
    char* author;
    int bookID;
    int quantity;
    float price;
    static int totalBooks;

public:

    Library(const Library& library) : bookID(library.bookID), quantity(library.quantity), price(library.price){
        bookTitle = new char[strlen(library.bookTitle)];
        strcpy(this->bookTitle, library.bookTitle);
        author = new char[strlen(library.author)];
        strcpy(this->author, library.author);
    }

    char* getBookTitle(){
        return bookTitle;
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

    void setBookTitle(char* title){
        bookTitle = title;
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
    for(int i=0;i<Library::getTotalBooks();i++){
        if(books[i].getBookID() == bookID){
            for(int j=i;j<Library::getTotalBooks()-1;j++){
                books[j] = books[j + 1];
            }
            Library::setTotalBooks(Library::getTotalBooks() - 1);
            break;
        }
    }
}

void sortByTitle(Library books[]){
    for(int i=0;i<Library::getTotalBooks();i++){
        for(int j=i+1;j<Library::getTotalBooks();j++){
            if(books[i].getBookTitle()[0]>books[j].getBookTitle()[0]){
                Library temp(books[i]);
                books[i] = Library(books[j]);
                books[j] = Library(temp);
            }
        }
    }
}

void sortByAuthor(Library books[]){
    for(int i=0;i<Library::getTotalBooks();i++){
        for(int j=i+1;j<Library::getTotalBooks();j++){
            if(books[i].getAuthor()[0]>books[j].getAuthor()[0]){
                Library temp(books[i]);
                books[i] = Library(books[j]);
                books[j] = Library(temp);
            }
        }
    }
}

void sortByPrice(Library books[]){
    for(int i=0;i<Library::getTotalBooks();i++){
        for(int j=i+1;j<Library::getTotalBooks();j++){
            if(books[i].getPrice()>books[j].getPrice()){
                Library temp(books[i]);
                books[i] = Library(books[j]);
                books[j] = Library(temp);
            }
        }
    }
}

bool searchByTitle(Library books[], char* titlename){
    for(int i=0;i<Library::getTotalBooks();i++){
        if(strcmp(books[i].getBookTitle(), titlename) == 0) return true;
    }
    return false;
}

Library mostExpensiveBook(Library books[]){
    Library max = books[0];
    for(int i=1;i<Library::getTotalBooks();i++){
        if(books[i].getPrice()>max.getPrice()) max = Library(books[i]);
    }
    return max;
}



int main(){

    

    return 0;
}