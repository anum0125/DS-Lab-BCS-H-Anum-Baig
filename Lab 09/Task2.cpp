#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int price;
    int height;
    Node* left;
    Node* right;
    Node(int p) { price = p; height = 1; left = right = NULL; }
};

int getHeight(Node* n) {
    if (!n) return 0;
    return n->height;
}

int getBalance(Node* n) {
    if (!n) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int price) {
    if (!root) return new Node(price);
    if (price < root->price) root->left = insertNode(root->left, price);
    else if (price > root->price) root->right = insertNode(root->right, price);
    else return root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBalance(root);
    if (bf > 1 && price < root->left->price) return rotateRight(root);
    if (bf < -1 && price > root->right->price) return rotateLeft(root);
    if (bf > 1 && price > root->left->price) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && price < root->right->price) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void rangeQuery(Node* root, int low, int high) {
    if (!root) return;
    if (root->price > low) rangeQuery(root->left, low, high);
    if (root->price >= low && root->price <= high)
        cout << root->price << " ";
    if (root->price < high) rangeQuery(root->right, low, high);
}

int main() {
    Node* root = NULL;
    int prices[] = {500, 200, 800, 100, 300, 700, 900};
    int n = sizeof(prices) / sizeof(prices[0]);
    for (int i = 0; i < n; i++)
        root = insertNode(root, prices[i]);
    int x, y;
    cout << "Enter range (low high): ";
    cin >> x >> y;
    rangeQuery(root, x, y);
    cout << endl;
    return 0;
}
