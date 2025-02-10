#include <iostream>
using namespace std;
class Book{
    private:
        string bookname;
        string ISBN;
        string author;
        string publish;
    public:
        Book(string b, string i, string a,string p){
            bookname = b;
            ISBN = i;
            author = a;
            publish = p;
        }
        void setbookname(string b){
            bookname = b;
        }
        void setISBN(string i){
            ISBN = i;
        }
        void setauthor(string a ){
            author = a;
        }
        void setpublish(string p){
            publish = p;
        }
        string getbookname(){
            return bookname;
        }
        string getISBN(){
            return ISBN;
        }
        string getauthor(){
            return author;
        }
        string getpublish(){
            return publish;
        }
         string getBookInfo() {
            return "Book Name: " + bookname + "\nISBN: " + ISBN + "\nAuthor: " + author + "\nPublisher: " + publish;
        }
};
void BookTest(){
   Book books[5] = {
        Book("The Great Gatsby", "978-0743273565", "F. Scott Fitzgerald", "Scribner"),
        Book("To Kill a Mockingbird", "978-0061120084", "Harper Lee", "J.B. Lippincott & Co."),
        Book("1984", "978-0451524935", "George Orwell", "Secker & Warburg"),
        Book("Pride and Prejudice", "978-1503290563", "Jane Austen", "T. Egerton"),
        Book("Moby-Dick", "978-1503280786", "Herman Melville", "Harper & Brothers")
    };
    for (int i = 0; i < 5; i++) {
        cout << "\nBook " << i + 1 << " Details:" << endl;
        cout << books[i].getBookInfo() << endl;
    }
}
int main()
{
    BookTest();
    return 0;
}