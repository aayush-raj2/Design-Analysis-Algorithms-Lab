//(Using Priority Queue)
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;

    if (!root->left && !root->right)
        cout << root->data << ": " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    char data[] = {'A','B','C','D'};
    int freq[] = {5,9,12,13};
    int n = 4;

    priority_queue<Node*, vector<Node*>, compare> pq;

    for(int i=0;i<n;i++)
        pq.push(new Node(data[i], freq[i]));

    while(pq.size() > 1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
    return 0;
}
