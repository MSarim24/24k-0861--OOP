#include <iostream>
using namespace std;

class Book {
    private:
        string title;
        string isbn;
    public:
        Book(string bookTitle, string bookIsbn) : title(bookTitle), isbn(bookIsbn) {}
        string getTitle() { return title; }
        string getIsbn() { return isbn; }
};

class Catalog {
    private:
        Book* books[100];
        int count;
    public:
        Catalog() : count(0) {}
        void addBook(Book* book) {
            if (count < 100) {
                books[count++] = book;
            }
        }
        Book* findBook(string isbn) {
            for (int i = 0; i < count; i++) {
                if (books[i]->getIsbn() == isbn) {
                    return books[i];
                }
            }
            return nullptr;
        }
};

class Library {
    private:
        Catalog catalog;
        Book* books[100];
        int bookCount;
    public:
        Library() : bookCount(0) {}
        void addBook(Book* book) {
            if (bookCount < 100) {
                books[bookCount++] = book;
                catalog.addBook(book);
            }
        }
        void findBookInCatalog(string isbn) {
            Book* book = catalog.findBook(isbn);
            if (book) {
                cout << "Book Found: " << book->getTitle() << endl;
            } else {
                cout << "Book Not Found" << endl;
            }
        }
};
int main() {
    Book book1("Harry Potter and the Sorcerer's Stone", "101");
    Book book2("The Hobbit", "202");
    Book book3("The Catcher in the Rye", "303");

    Library myLibrary;

    myLibrary.addBook(&book1);
    myLibrary.addBook(&book2);
    myLibrary.addBook(&book3);

    cout << "Searching for books in the library..." << endl;

    cout << "Looking for ISBN 101: ";
    myLibrary.findBookInCatalog("101");

    cout << "Looking for ISBN 202: ";
    myLibrary.findBookInCatalog("202");

    cout << "Looking for ISBN 404: ";
    myLibrary.findBookInCatalog("404");

    cout << "Library search complete!" << endl;

    return 0;
}