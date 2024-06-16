#include<iostream>
#include<cstring>
using namespace std;

class Library {
private:
    char *bookTitle;
    char *author;
    int bookID;
    int quantity;
    float price;
    static int totalBooks;

public:
    //Constructors
    Library() : bookTitle(nullptr), author(nullptr) {
        bookID = 0;
        quantity = 0;
        price = 0.0;
    }

    Library(char* title, char* authorName, int id, int newQuantity, float bookPrice) {
        bookTitle = new char[strlen(title) + 1];
        strcpy(bookTitle, title);
        author = new char[strlen(authorName) + 1];
        strcpy(author, authorName);
        bookID = id;
        quantity = newQuantity;
        price = bookPrice;
        totalBooks += newQuantity;
    }

    // ~Library() {
    //     delete[] bookTitle;
    //     delete[] author;
    //     totalBooks -= quantity;
    // }

    //Getters
    char* getBookTitle() { return bookTitle; }
    char* getAuthor() { return author; }
    int getBookID() { return bookID; }
    int getQuantity() { return quantity; }
    float getPrice() { return price; }

    static int getTotalBooks() {
        return totalBooks;
    }

    //Setters
    void setBookTitle(char* title) {
        bookTitle = new char[strlen(title) + 1];
        strcpy(bookTitle, title);
    }

    void setAuthor(char* authorName) {
        author = new char[strlen(authorName) + 1];
        strcpy(author, authorName);
    }

    void setBookID(int bookID) { this->bookID = bookID; }
    void setPrice(float price) { this->price = price; }
    static void setTotalBooks(int total) { totalBooks = total; }

    void setQuantity(int newQuantity) {  
        if (newQuantity >= 0) {
            totalBooks += (newQuantity - quantity);
            this->quantity = newQuantity;
        } else {
            cout << "Quantity cannot be negative." << endl;
        }
    }

    //Other member functions
    void calcTotalPrice() {
        float totalPrice = price * quantity;
        cout << "The total price for all copies is Rs: " << totalPrice << endl;
    }
};

int Library :: totalBooks = 0;
 
Library getBook_at(Library books[100], int index) {
    return books[index];
}

void addBook(Library books[100], Library newBook) {
    for (int i = 0; i < 100; i++) {
        if (books[i].getBookID() == 0) {
            books[i] = newBook;
            return;
        }
    }
    cout << "Library is full. Cannot add more books," << endl;
}

void removeBook(Library books[100], int bookID) {
    for (int i = 0; i < 100; i++) {
        if (books[i].getBookID() == bookID) {
            books[i] = Library();
        }
    }
    cout << "Book of ID " << bookID << " not found." << endl;
}

void SortByTitle(Library books[100]) {
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99 - i; j++) {
            if (strcmp(books[i].getBookTitle(), books[j + 1].getBookTitle()) > 0) {
                Library temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

}

void SortByAuthor(Library books[100]) {
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99 - i; j++) {
            if (strcmp(books[i].getAuthor(), books[j + 1].getAuthor()) > 0) {
                Library temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void SortByPrice(Library books[100]) {
    for (int i = 0; i < 99; i++) {
        for (int j = 0; j < 99 - i; j++) {
            if (books[i].getPrice() > books[j + 1].getPrice()) {
                Library temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

bool searchByTittle(Library books[100], char* titlename) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(books[i].getBookTitle(), titlename) == 0) {
            return true;
        }
    }
    return false;
}

Library mostExpensiveBook(Library books[100]) {
    Library mostExpensive = books[0];
    for (int i = 0; i < 100; i++) {
        if (books[i].getPrice() > mostExpensive.getPrice()) {
            mostExpensive = books[i];
        }
    }
    return mostExpensive;
}

void displayBooks(Library books[100]) {
    cout << "Books in the library: " << endl;
    for (int i = 0; i < 100; i++) {
        if (books[i].getBookID() != 0) {
            cout << "Book Title: " << books[i].getBookTitle() << ", Author: " << books[i].getAuthor() << ", Price: " << books[i].getPrice() << ", Quantity: " << books[i].getQuantity() << endl;
        }
    }
    cout << endl;
}

int main() {
    Library books[100];

    int numBooks;
    cout << "Enter the total number of books: ";
    cin >> numBooks;

    for (int i = 0; i < numBooks && i < 100; i++) {
        char bookName[100];
        char authorName[100];
        int id;
        int booksQuantity;
        float bookPrice;

        cout << "Enter details for Book " << i + 1 << ":" << endl;
        cout << "Book title: ";
        cin.ignore();
        cin.getline(bookName, 100);
        cout << "Name of author: ";
        //cin.ignore();
        cin.getline(authorName, 100);
        cout << "ID: ";
        cin >> id;
        cout << "Quantity of books: ";
        cin >> booksQuantity;
        cout << "Price: ";
        cin >> bookPrice;

        books[i] = Library(bookName, authorName, id, booksQuantity, bookPrice);
    }

    displayBooks(books);

    SortByTitle(books);
    cout << "Books sorted by title:" << endl;
    displayBooks(books);

    SortByAuthor(books);
    cout << "Books sorted by author:" << endl;
    displayBooks(books);

    SortByPrice(books);
    cout << "Books sorted by price:" << endl;
    displayBooks(books);


    Library mostExpensive =  mostExpensiveBook(books);
    cout << "The most expensive book of the library is: " << mostExpensive.getBookTitle() <<  " by " << mostExpensive.getAuthor() << endl;

    char newBookName[100];
    char newAuthorName[100];
    int newID;
    int newQuantity;
    float newPrice;

    cout << "Enter details for the new book:" << endl;
    cout << "Book title: ";
    cin.ignore();
    cin.getline(newBookName, 100);
    cout << "Name of author: ";
    //cin.ignore(); // Uncomment if needed
    cin.getline(newAuthorName, 100);
    cout << "ID: ";
    cin >> newID;
    cout << "Quantity of books: ";
    cin >> newQuantity;
    cout << "Price: ";
    cin >> newPrice;

    addBook(books, Library(newBookName, newAuthorName, newID, newQuantity, newPrice));

    displayBooks(books);

    int removeID;
    cout << "Enter the ID of the book to remove: ";
    cin >> removeID;

    removeBook(books, removeID);

    displayBooks(books);

    // Search by title
    char searchTitle[100];
    cout << "Enter the title to search: ";
    cin.ignore();
    cin.getline(searchTitle, 100);

    if (searchByTittle(books, searchTitle)) {
        cout << "Book found!" << endl;
    } else {
        cout << "Book not found!" << endl;
    }

    return 0;
}