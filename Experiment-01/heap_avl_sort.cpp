#include <iostream>
using namespace std;

/* ===================== HEAP SORT ===================== */

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/* ===================== AVL TREE ===================== */

struct Node {
    int key;
    Node *left, *right;
    int height;
};

int height(Node *n) {
    return n ? n->height : 0;
}

int getBalance(Node *n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insertAVL(Node* node, int key) {
    if (!node)
        return newNode(key);

    if (key < node->key)
        node->left = insertAVL(node->left, key);
    else
        node->right = insertAVL(node->right, key);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

/* ===================== MAIN MENU ===================== */

int main() {
    int n, arr[50], choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Sort using Heap Sort\n";
        cout << "2. Sort using AVL Tree\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            heapSort(arr, n);
            cout << "Sorted using Heap Sort:\n";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        else if (choice == 2) {
            Node* root = NULL;
            for (int i = 0; i < n; i++)
                root = insertAVL(root, arr[i]);

            cout << "Sorted using AVL Tree (Inorder Traversal):\n";
            inorder(root);
            cout << endl;
        }

    } while (choice != 3);

    return 0;
}
