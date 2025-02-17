#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author, publisher;
    double price;
    int stock;

public:
    Book(string t, string a, string p, double pr, int s) : title(t), author(a), publisher(p), price(pr), stock(s) {}

    bool isAvailable(string t, string a) const {
        return title == t && author == a;
    }

    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher << "\nPrice: " << price << "\nStock: " << stock << endl;
    }

    bool sellCopies(int count) {
        if (count <= stock) {
            stock -= count;
            cout << "Total cost: " << count * price << endl;
            return true;
        }
        cout << "Required copies not in stock" << endl;
        return false;
    }
};

class BookShop {
private:
    Book* books;
    int size;

public:
    BookShop(Book* b, int s) : books(b), size(s) {}

    Book* findBook(string t, string a) {
        for (int i = 0; i < size; i++) {
            if (books[i].isAvailable(t, a)) return &books[i];
        }
        return nullptr;
    }
};

int main() {
    Book inventory[] = {
        Book("C++ Basics", "John Doe", "Tech Press", 50.0, 10),
        Book("Python Guide", "Jane Smith", "CodeWorld", 40.0, 5)
    };
    BookShop shop(inventory, 2);

    string title, author;
    cout << "Enter title and author: ";
    getline(cin, title);
    getline(cin, author);

    Book* book = shop.findBook(title, author);
    if (book) {
        book->display();
        int copies;
        cout << "Enter copies to buy: ";
        cin >> copies;
        book->sellCopies(copies);
    } else {
        cout << "Book not available" << endl;
    }
    return 0;
}
