#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

// Selection sort with Priority Queue
void selectionSortWithPQ(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

// Insertion sort with Priority Queue
void insertionSortWithPQ(int arr[], int n) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pq.top();
        pq.pop();
    }
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, choice;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Choose sorting algorithm:\n1. Selection sort with Priority Queue\n2. Insertion sort with Priority Queue\n3. Bubble sort\n";
    cin >> choice;

    switch(choice) {
        case 1:
            selectionSortWithPQ(arr, n);
            break;
        case 2:
            insertionSortWithPQ(arr, n);
            break;
        case 3:
            bubbleSort(arr, n);
            break;
        default:
            cout << "Invalid choice.\n";
            return 0;
    }

    ofstream outfile;
    outfile.open("sorted.txt");

    for (int i = 0; i < n; i++) {
        outfile << arr[i] << " ";
    }

    outfile.close();

    cout << "Sorting completed. Output written to sorted.txt.\n";

    return 0;
}
