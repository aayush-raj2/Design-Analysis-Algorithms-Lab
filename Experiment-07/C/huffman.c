#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char data[] = {'A','B','C','D'};
    int freq[] = {5,9,12,13};

    printf("Huffman Coding requires priority queue for full implementation.\n");
    printf("This demo focuses on structure and printing concept.\n");

    return 0;
}
