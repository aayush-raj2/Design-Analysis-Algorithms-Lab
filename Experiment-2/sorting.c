#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int n, choice;
    clock_t start, end;
    double cpu_time;

    printf("Enter number of elements (>=10000): ");
    scanf("%d", &n);

    if (n < 10000) {
        printf("n must be at least 10000\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        copyArray(arr, temp, n);

        switch (choice) {
        case 1:
            start = clock();
            bubbleSort(temp, n);
            end = clock();
            break;

        case 2:
            start = clock();
            insertionSort(temp, n);
            end = clock();
            break;

        case 3:
            return 0;
        default:
            printf("Invalid choice\n");
            continue;
        }

        cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("CPU Time: %lf seconds\n", cpu_time);

    } while (choice != 3);

    free(arr);
    free(temp);
    return 0;
}
