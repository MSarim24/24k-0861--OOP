#include <iostream>
using namespace std;

class Book {
protected:
    string genre;
public:
    Book(string g) : genre(g) {}
    virtual void display() = 0;
    virtual ~Book() {}
};

class Novel : public Book {
private:
    string title, author;
public:
    Novel(string t, string a) : Book("Novel"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }
};

class Mystery : public Book {
private:
    string title, author;
public:
    Mystery(string t, string a) : Book("Mystery"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }
};

int main() {
    Novel n("Pride and Prejudice", "Jane Austen");
    Mystery m("Sherlock Holmes", "Arthur Conan Doyle");
    
    n.display();
    cout << "\n";
    m.display();
    
    return 0;
}
