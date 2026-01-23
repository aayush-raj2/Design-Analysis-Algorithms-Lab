#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void bubbleSort(vector<int> &a) {
    for (int i = 0; i < a.size() - 1; i++)
        for (int j = 0; j < a.size() - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void insertionSort(vector<int> &a) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n, choice;
    cout << "Enter number of elements (>=10000): ";
    cin >> n;

    if (n < 10000) {
        cout << "n must be at least 10000\n";
        return 0;
    }

    vector<int> arr(n), temp;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n1. Bubble Sort\n2. Insertion Sort\n3. Exit\nChoice: ";
        cin >> choice;

        temp = arr;
        clock_t start = clock();

        if (choice == 1)
            bubbleSort(temp);
        else if (choice == 2)
            insertionSort(temp);
        else
            break;

        clock_t end = clock();
        double cpu_time = double(end - start) / CLOCKS_PER_SEC;
        cout << "CPU Time: " << cpu_time << " seconds\n";

    } while (choice != 3);

    return 0;
}
