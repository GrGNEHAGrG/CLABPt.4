#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int pages;
public:
    Book(string t = "Untitled", int p = 0) : title(t), pages(p) {
        cout << "Book Constructor: \"" << title << "\" with " << pages << " pages\n";
    }

    ~Book() {
        cout << "Book Destructor: \"" << title << "\" destroyed\n";
    }

    void display() const {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

class BookShelf {
private:
    Book* collection;
    int count;
public:
    BookShelf() {
        count = 3;
        collection = new Book[count]{
            Book("C++ Fundamentals", 300),
            Book("Data Structures", 450),
            Book("Algorithms", 500)
        };
        cout << "BookShelf Constructor: Shelf initialized with " << count << " books\n";
    }

    ~BookShelf() {
        delete[] collection;
        cout << "BookShelf Destructor: Shelf destroyed\n";
    }

    void showBooks() const {
        for (int i = 0; i < count; ++i) {
            collection[i].display();
        }
    }
};

void example1() {
    cout << "EXAMPLE 1: Array of Book objects\n";
    cout << "--------------------------------\n";

    Book library[3] = {
        Book("C++ Fundamentals", 300),
        Book("Data Structures", 450),
        Book("Algorithms", 500)
    };

    cout << "\n--- Library Contents ---\n";
    for (int i = 0; i < 3; ++i) {
        library[i].display();
    }

    cout << "\n--- End of Program ---\n";
}

void example2() {
    cout << "\n\nEXAMPLE 2: BookShelf\n";
    cout << "----------------------------------------\n";

    BookShelf* shelf = new BookShelf();
    cout << "\nBooks on shelf:\n";
    shelf->showBooks();
    delete shelf;

    cout << "\n--- End of Program ---\n";
}

int main() {
    example1();
    example2();
    return 0;
}
