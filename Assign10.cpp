#include <iostream>
#include <string>
using namespace std;

// Structure for a Music Track
struct MusicTrack {
    string title;
    string artist;
    string album;
    string genre;
    int duration; // Duration in seconds
    int releaseYear;
    MusicTrack* next;

    // Constructor to initialize track details
    MusicTrack(string t, string a, string al, string g, int d, int r)
        : title(t), artist(a), album(al), genre(g), duration(d), releaseYear(r), next(nullptr) {}
};

// Music Library System class
class MusicLibrary {
private:
    MusicTrack* head; // Pointer to the head of the circular linked list

public:
    // Constructor
    MusicLibrary() : head(nullptr) {}

    // Add a new music track
    void addTrack(const string& title, const string& artist, const string& album, const string& genre, int duration, int releaseYear) {
        MusicTrack* newTrack = new MusicTrack(title, artist, album, genre, duration, releaseYear);
        if (!head) {
            head = newTrack;
            head->next = head; // Point to itself to form a circular list
        } else {
            MusicTrack* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newTrack;
            newTrack->next = head; // Complete the circle
        }
        cout << "Track added: " << title << endl;
    }

    // Remove a music track by title
    void removeTrack(const string& title) {
        if (!head) {
            cout << "No tracks in the library.\n";
            return;
        }

        MusicTrack* current = head;
        MusicTrack* prev = nullptr;

        // Find the track to remove
        do {
            if (current->title == title) {
                if (current == head && current->next == head) {
                    // Only one track in the list
                    delete current;
                    head = nullptr;
                } else if (current == head) {
                    // Removing head and more than one track in the list
                    MusicTrack* temp = head;
                    while (temp->next != head) {
                        temp = temp->next;
                    }
                    head = head->next;
                    temp->next = head;
                    delete current;
                } else {
                    // Removing non-head track
                    prev->next = current->next;
                    delete current;
                }
                cout << "Track removed: " << title << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Track not found: " << title << endl;
    }

    // Update music track information by title
    void updateTrack(const string& title) {
        if (!head) {
            cout << "No tracks in the library.\n";
            return;
        }

        MusicTrack* temp = head;
        do {
            if (temp->title == title) {
                cout << "Updating information for track: " << title << endl;
                cout << "Enter new artist: ";
                cin >> temp->artist;
                cout << "Enter new album: ";
                cin >> temp->album;
                cout << "Enter new genre: ";
                cin >> temp->genre;
                cout << "Enter new duration (in seconds): ";
                cin >> temp->duration;
                cout << "Enter new release year: ";
                cin >> temp->releaseYear;
                cout << "Track information updated.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Track not found: " << title << endl;
    }

    // Search for a music track by title
    void searchTrack(const string& title) {
        if (!head) {
            cout << "No tracks in the library.\n";
            return;
        }

        MusicTrack* temp = head;
        do {
            if (temp->title == title) {
                cout << "Track found:\n";
                cout << "Title: " << temp->title << "\n";
                cout << "Artist: " << temp->artist << "\n";
                cout << "Album: " << temp->album << "\n";
                cout << "Genre: " << temp->genre << "\n";
                cout << "Duration: " << temp->duration << " seconds\n";
                cout << "Release Year: " << temp->releaseYear << "\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Track not found: " << title << endl;
    }

    // Display all music tracks
    void displayAllTracks() {
        if (!head) {
            cout << "No tracks in the library.\n";
            return;
        }

        MusicTrack* temp = head;
        cout << "All Tracks:\n";
        do {
            cout << "Title: " << temp->title << "\n";
            cout << "Artist: " << temp->artist << "\n";
            cout << "Album: " << temp->album << "\n";
            cout << "Genre: " << temp->genre << "\n";
            cout << "Duration: " << temp->duration << " seconds\n";
            cout << "Release Year: " << temp->releaseYear << "\n";
            cout << "-----------------------------\n";
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    MusicLibrary library;

    // Menu for music library management
    int choice;
    do {
        cout << "\nMusic Library System\n";
        cout << "1. Add Track\n";
        cout << "2. Remove Track\n";
        cout << "3. Update Track Information\n";
        cout << "4. Search Track\n";
        cout << "5. Display All Tracks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string title, artist, album, genre;
        int duration, releaseYear;

        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter track title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter album: ";
                getline(cin, album);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter duration (in seconds): ";
                cin >> duration;
                cout << "Enter release year: ";
                cin >> releaseYear;
                library.addTrack(title, artist, album, genre, duration, releaseYear);
                break;

            case 2:
                cin.ignore();
                cout << "Enter track title to remove: ";
                getline(cin, title);
                library.removeTrack(title);
                break;

            case 3:
                cin.ignore();
                cout << "Enter track title to update: ";
                getline(cin, title);
                library.updateTrack(title);
                break;

            case 4:
                cin.ignore();
                cout << "Enter track title to search: ";
                getline(cin, title);
                library.searchTrack(title);
                break;

            case 5:
                library.displayAllTracks();
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
