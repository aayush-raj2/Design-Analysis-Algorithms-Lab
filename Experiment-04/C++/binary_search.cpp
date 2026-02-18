#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> arr = {3, 9, 27, 38, 43};
    int key = 38;

    int result = binarySearch(arr, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}
