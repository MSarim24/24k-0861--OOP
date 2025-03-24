#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string id, string pub) : title(t), publicationDate(pDate), uniqueID(id), publisher(pub) {}
    virtual void displayInfo() {
        cout << "Title: " << title << " | Publication Date: " << publicationDate << " | ID: " << uniqueID << " | Publisher: " << publisher << endl;
    }
    virtual void checkOut() { cout << title << " checked out." << endl; }
    virtual void returnItem() { cout << title << " returned." << endl; }
};

class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string id, string pub, string a, string isbn, int pages) : Media(t, pDate, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << " | ISBN: " << ISBN << " | Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
private:
    string director, rating;
    double duration;
public:
    DVD(string t, string pDate, string id, string pub, string d, double dur, string r) : Media(t, pDate, id, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << " | Duration: " << duration << " min | Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string id, string pub, string art, int tracks, string g) : Media(t, pDate, id, pub), artist(art), numberOfTracks(tracks), genre(g) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << " | Tracks: " << numberOfTracks << " | Genre: " << genre << endl;
    }
};

int main() {
    Book book("C++ Programming", "2023", "B001", "Tech Publishers", "John Doe", "123-456-789", 350);
    DVD dvd("Inception", "2010", "D100", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD cd("Thriller", "1982", "C200", "Epic Records", "Michael Jackson", 9, "Pop");

    vector<Media*> library = {&book, &dvd, &cd};
    
    cout << "--- Library Media Details ---" << endl;
    for (Media* media : library) {
        media->displayInfo();
    }
    
    return 0;
}
