#include <iostream>
using namespace std;
int temp,j,i;
// Function to sort the array in ascending order
void sortArray(int arr[], int n) {
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to copy costs of books with cost less than 500 in new array
void copyLessThan500(int arr[], int n, int newArr[]) {
    int j = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] < 500) {
            newArr[j] = arr[i];
            j++;
        }
    }
}

// Function to delete duplicate entries using temporary array
void deleteDuplicatesTemp(int arr[], int n) {
    int temp[n];
    int j = 0;
    for (i = 0; i < n; i++) {
        bool duplicate = false;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            temp[j] = arr[i];
            j++;
        }
    }
    for (i = 0; i < j; i++) {
        arr[i] = temp[i];
    }
    n = j;
}

// Function to delete duplicate entries without using temporary array
void deleteDuplicatesNoTemp(int arr[], int n) {
    for (i = 0; i < n; i++) {
        for ( j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
}

// Function to count number of books with cost more than 500
int countMoreThan500(int arr[], int n) {
    int count = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] > 500) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Enter the number of books: ";
    cin >> N;

    int cost[N];
    cout << "Enter the costs of books: ";
    for (i = 0; i < N; i++) {
        cin >> cost[i];
    }

    // Sort the array in descending order
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (cost[i] < cost[j]) {
                temp = cost[i];
                cost[i] = cost[j];
                cost[j] = temp;
            }
        }
    }

    // Copy costs of books with cost less than 500 in new array
    int newArr[N];
    copyLessThan500(cost, N, newArr);

    // Delete duplicate entries using temporary array
    deleteDuplicatesTemp(newArr, N);

    // Delete duplicate entries without using temporary array
    deleteDuplicatesNoTemp(newArr, N);

    // Count number of books with cost more than 500
    int count = countMoreThan500(cost, N);

    cout << "Number of books with cost more than 500: " << count << endl;

    return 0;
}