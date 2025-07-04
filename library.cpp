#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;

class Book {
private:
    int bookID;
    string title;
    string author;

public:
    void input() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";///getline() in C++ is used to read a full line of text, 
                                   ///including spaces, until a newline (\n) is encountered.
        getline(cin, author);
    }

    void display() const {
        cout << "Book ID: " << bookID << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "-------------------------\n";
    }

    int getID() const {
        return bookID;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    void addBook() {
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full!\n";
            return;
        }
        books[bookCount].input();
        bookCount++;
        cout << "Book added successfully.\n";
    }

    void displayBooks() const {
        if (bookCount == 0) {
            cout << "No books in library.\n";
            return;
        }
        for (int i = 0; i < bookCount; ++i) {
            books[i].display();
        }
    }

    void searchBook(int id) const {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getID() == id) {
                cout << "Book found:\n";
                books[i].display();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void deleteBook(int id) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i].getID() == id) {
                // Shift remaining books left
                for (int j = i; j < bookCount - 1; ++j) {
                    books[j] = books[j + 1];
                }
                bookCount--;
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book ID not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Delete Book by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3: {
                int id;
                cout << "Enter Book ID to search: ";
                cin >> id;
                lib.searchBook(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Book ID to delete: ";
                cin >> id;
                lib.deleteBook(id);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
