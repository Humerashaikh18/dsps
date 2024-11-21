#include <iostream>
using namespace std;

int n;

class stud {
private:
    int rollNumber;
    string name;
    string address;

public:
    void accept();
    void display() ;
    int linearSearch(int rollNumber) ;
    int binarySearch(int rollNumber) ;
    void bubbleSort();
};

stud s[100];

void stud::accept() {
    cout << "Enter the roll number, name, and address of the student:\n";
    cin >> rollNumber >> name >> address;
}

void stud::display()  {
    cout << "\n" << rollNumber << "\t" << name << "\t" << address;
}

int stud::linearSearch(int rollNumber)  {
    int f=-1;
    for (int i = 0; i < n; i++) {
        
        if (s[i].rollNumber == rollNumber) {
            f=1;
            
            break;
        }
    }
     if (f!= -1) {
           cout << "Roll number " << rollNumber << " attended the training ";
        } else {
            cout << "Roll number " << rollNumber << " not attended training." << endl;
        } 
        return 0; 
}

void stud::bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].rollNumber > s[j].rollNumber) {
                stud temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

int stud::binarySearch(int rollNumber)  {
    int left = 0, right = n - 1,f=-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (s[mid].rollNumber == rollNumber) {
             f=1;
            
           
            break;
        }

        if (s[mid].rollNumber < rollNumber)
            left = mid + 1;
        else
            right = mid - 1;
    }
       if (f!= -1) {
           cout << "Roll number " << rollNumber << " attended the training ";
        } else {
            cout << "Roll number " << rollNumber << " not attended training";
        }  
        return 0;
}

int main() {
    int choice, rollNumber;

    while (true) {
        cout << "\nChoose the option:\n";
        cout << "1. ACCEPT DATA\n";
        cout << "2. DISPLAY DATA\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the number of students who attended the training program: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                s[i].accept();
            }
            break;

        case 2:
            cout << "\nRoll No\tName\tAddress";
            for (int i = 0; i < n; i++) {
                s[i].display();
            }
            cout << endl;
            break;

        case 3:
            cout << "Enter the roll number to search: ";
            cin >> rollNumber;
            
                s[0].linearSearch(rollNumber);
                
            
            break;

        case 4:
            cout << "Enter the roll number to search: ";
            cin >> rollNumber;
            s[0].bubbleSort();  
            
            s[0].binarySearch(rollNumber);
                
            
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
