#include <iostream>
#include <string>
using namespace std;

// Structure for a Donor
struct Donor {
    string name;
    string email;
    string phone;
    double totalDonation;
    Donor* prev;
    Donor* next;

    // Constructor to initialize donor details
    Donor(string n, string e, string p, double d)
        : name(n), email(e), phone(p), totalDonation(d), prev(nullptr), next(nullptr) {}
};

// Charity Management System class
class CharityManagementSystem {
private:
    Donor* head; // Head pointer to the doubly linked list
    Donor* tail; // Tail pointer for efficiency in adding at the end

public:
    // Constructor
    CharityManagementSystem() : head(nullptr), tail(nullptr) {}

    // Add a new donor
    void addDonor(const string& name, const string& email, const string& phone, double totalDonation) {
        Donor* newDonor = new Donor(name, email, phone, totalDonation);
        if (!head) {
            head = tail = newDonor;
        } else {
            tail->next = newDonor;
            newDonor->prev = tail;
            tail = newDonor;
        }
        cout << "Donor added: " << name << endl;
    }

    // Remove a donor by name
    void removeDonor(const string& name) {
        if (!head) {
            cout << "No donors in the database.\n";
            return;
        }

        Donor* temp = head;
        while (temp && temp->name != name) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Donor not found: " << name << endl;
            return;
        }

        // Removing the donor
        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Donor removed: " << name << endl;
    }

    // Update donor information by name
    void updateDonor(const string& name) {
        Donor* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << "Updating information for donor: " << name << endl;
                cout << "Enter new email: ";
                cin >> temp->email;
                cout << "Enter new phone: ";
                cin >> temp->phone;
                cout << "Enter updated total donation: ";
                cin >> temp->totalDonation;
                cout << "Donor information updated.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Donor not found: " << name << endl;
    }

    // Search for a donor by name
    void searchDonor(const string& name) {
        Donor* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << "Donor found:\n";
                cout << "Name: " << temp->name << "\n";
                cout << "Email: " << temp->email << "\n";
                cout << "Phone: " << temp->phone << "\n";
                cout << "Total Donation: $" << temp->totalDonation << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Donor not found: " << name << endl;
    }

    // Display all donors
    void displayAllDonors() {
        if (!head) {
            cout << "No donors in the database.\n";
            return;
        }

        Donor* temp = head;
        cout << "All Donors:\n";
        while (temp) {
            cout << "Name: " << temp->name << "\n";
            cout << "Email: " << temp->email << "\n";
            cout << "Phone: " << temp->phone << "\n";
            cout << "Total Donation: $" << temp->totalDonation << "\n";
            cout << "-----------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    CharityManagementSystem charity;

    // Menu for charity management
    int choice;
    do {
        cout << "\nCharity Management System\n";
        cout << "1. Add Donor\n";
        cout << "2. Remove Donor\n";
        cout << "3. Update Donor Information\n";
        cout << "4. Search Donor\n";
        cout << "5. Display All Donors\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name, email, phone;
        double totalDonation;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter donor name: ";
                getline(cin, name);
                cout << "Enter donor email: ";
                cin >> email;
                cout << "Enter donor phone: ";
                cin >> phone;
                cout << "Enter total donation amount: ";
                cin >> totalDonation;
                charity.addDonor(name, email, phone, totalDonation);
                break;

            case 2:
                cin.ignore();
                cout << "Enter donor name to remove: ";
                getline(cin, name);
                charity.removeDonor(name);
                break;

            case 3:
                cin.ignore();
                cout << "Enter donor name to update: ";
                getline(cin, name);
                charity.updateDonor(name);
                break;

            case 4:
                cin.ignore();
                cout << "Enter donor name to search: ";
                getline(cin, name);
                charity.searchDonor(name);
                break;

            case 5:
                charity.displayAllDonors();
                break;

            case 6:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
