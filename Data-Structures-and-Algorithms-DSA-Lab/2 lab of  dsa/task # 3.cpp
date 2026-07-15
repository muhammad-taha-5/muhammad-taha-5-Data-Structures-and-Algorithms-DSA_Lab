#include <iostream>
#include <string>
using namespace std;

template <class T>
void linearSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {  // FIX: Use operator< instead of getTitle()[0]
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <class T>
int linearSearch(T arr[], int n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;  // FIX: Return -1 instead of 0 when not found
}

class Item {
public:
    virtual void display() = 0;
};

class Book : public Item {
    string title;
    string author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    int getPages() {
        return pages;
    }

    string getTitle() {
        return title;
    }

    bool operator<(Book b) {
        return pages < b.pages;
    }

    bool operator==(string t) {
        return title == t;
    }

    void display() {
        cout << "Book: " << title << " | " << author << " | " << pages << endl;
    }
};

class Newspaper : public Item {
    string name;
    string date;
    string edition;

public:
    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getTitle() {  // FIX: Add getTitle() for template compatibility
        return name;
    }

    bool operator<(Newspaper n) {
        return edition < n.edition;
    }

    bool operator==(string n) {
        return name == n;
    }

    void display() {
        cout << "Newspaper: " << name << " | " << date << " | " << edition << endl;
    }
};

class Library {
    Book books[10];
    Newspaper newspapers[10];
    int bookCount = 0;
    int newsCount = 0;

public:

    void addBook(Book b) {
        books[bookCount++] = b;
    }

    void addNewspaper(Newspaper n) {
        newspapers[newsCount++] = n;
    }

    void displayCollection() {
        for (int i = 0; i < bookCount; i++)
            books[i].display();

        for (int i = 0; i < newsCount; i++)
            newspapers[i].display();
    }

    void sortBooksByPages() {
        linearSort(books, bookCount);
    }

    void sortNewspapersByEdition() {
        linearSort(newspapers, newsCount);
    }

    Book* searchBookByTitle(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i] == title)
                return &books[i];
        }
        return NULL;
    }

    Newspaper* searchNewspaperByName(string name) {
        for (int i = 0; i < newsCount; i++) {
            if (newspapers[i] == name)
                return &newspapers[i];
        }
        return NULL;
    }
};


int main() {
   
    Book book1("The Catcher in the Rye", "Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    // library object 
    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

   
    cout << "Before Sorting:\n";
    library.displayCollection();
 
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();
    

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }
 
      
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}