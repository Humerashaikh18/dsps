#include <iostream>
#include <string>
using namespace std;

// Structure for a Book
struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    Book* next;

    // Constructor to initialize a book
    Book(string t, string a, string i, bool avail) 
        : title(t), author(a), ISBN(i), isAvailable(avail), next(nullptr) {}
};

// Library class for linked list operations
class Library {
private:
    Book* head; // Head pointer to the linked list

public:
    // Constructor
    Library() : head(nullptr) {}

    // Add a book to the library
    void addBook(const string& title, const string& author, const string& ISBN, bool isAvailable) {
        Book* newBook = new Book(title, author, ISBN, isAvailable);
        if (!head) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "Book added: " << title << endl;
    }

    // Remove a book by ISBN
    void removeBook(const string& ISBN) {
        if (!head) {
            cout << "No books in the library.\n";
            return;
        }

        if (head->ISBN == ISBN) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "Book removed: " << ISBN << endl;
            return;
        }

        Book* temp = head;
        while (temp->next && temp->next->ISBN != ISBN) {
            temp = temp->next;
        }

        if (temp->next) {
            Book* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Book removed: " << ISBN << endl;
        } else {
            cout << "Book not found: " << ISBN << endl;
        }
    }

    // Search for a book by ISBN
    void searchBook(const string& ISBN) {
        Book* temp = head;
        while (temp) {
            if (temp->ISBN == ISBN) {
                cout << "Book found:\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Author: " << temp->author << "\n";
                cout << "ISBN: " << temp->ISBN << "\n";
                cout << "Availability: " << (temp->isAvailable ? "Available" : "Not Available") << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found: " << ISBN << endl;
    }

    // Display all books
    void displayBooks() {
        if (!head) {
            cout << "No books in the library.\n";
            return;
        }

        Book* temp = head;
        while (temp) {
            cout << "Title: " << temp->title << "\n";
            cout << "Author: " << temp->author << "\n";
            cout << "ISBN: " << temp->ISBN << "\n";
            cout << "Availability: " << (temp->isAvailable ? "Available" : "Not Available") << "\n";
            cout << "----------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    Library library;

    // Menu for library operations
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string title, author, ISBN;
        bool isAvailable;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                cin >> ISBN;
                cout << "Is the book available? (1 for Yes, 0 for No): ";
                cin >> isAvailable;
                library.addBook(title, author, ISBN, isAvailable);
                break;

            case 2:
                cin.ignore();
                cout << "Enter ISBN of the book to remove: ";
                cin >> ISBN;
                library.removeBook(ISBN);
                break;

            case 3:
                cin.ignore();
                cout << "Enter ISBN of the book to search: ";
                cin >> ISBN;
                library.searchBook(ISBN);
                break;

            case 4:
                library.displayBooks();
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
