#include <iostream>
#include <string>
using namespace std;

struct Node {
    int roll;
    int height;
    Node* left;
    Node* right;
    Node(int r) { roll = r; height = 1; left = right = NULL; }
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
    cout << "Rotation: Right Rotation (RR)" << endl;
    Node* x = y->left;
    Node* t = x->right;
    x->right = y;
    y->left = t;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotateLeft(Node* x) {
    cout << "Rotation: Left Rotation (LL)" << endl;
    Node* y = x->right;
    Node* t = y->left;
    y->left = x;
    x->right = t;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insertNode(Node* root, int roll) {
    if (!root) {
        cout << "Inserted: " << roll << endl;
        return new Node(roll);
    }

    if (roll < root->roll) root->left = insertNode(root->left, roll);
    else if (roll > root->roll) root->right = insertNode(root->right, roll);
    else return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalance(root);
    cout << "Balance Factor of " << root->roll << " = " << bf << endl;

    if (bf > 1 && roll < root->left->roll) return rotateRight(root);
    if (bf < -1 && roll > root->right->roll) return rotateLeft(root);
    if (bf > 1 && roll > root->left->roll) {
        cout << "Rotation: Left-Right Rotation (LR)" << endl;
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && roll < root->right->roll) {
        cout << "Rotation: Right-Left Rotation (RL)" << endl;
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* getMin(Node* n) {
    while (n->left) n = n->left;
    return n;
}

Node* deleteNode(Node* root, int roll) {
    if (!root) return root;

    if (roll < root->roll) root->left = deleteNode(root->left, roll);
    else if (roll > root->roll) root->right = deleteNode(root->right, roll);
    else {
        cout << "Deleted: " << roll << endl;
        if (!root->left || !root->right) {
            Node* t = root->left ? root->left : root->right;
            if (!t) {
                t = root;
                root = NULL;
            } else {
                *root = *t;
            }
            delete t;
        } else {
            Node* t = getMin(root->right);
            root->roll = t->roll;
            root->right = deleteNode(root->right, t->roll);
        }
    }

    if (!root) return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalance(root);
    cout << "Balance Factor of " << root->roll << " = " << bf << endl;

    if (bf > 1 && getBalance(root->left) >= 0) return rotateRight(root);
    if (bf > 1 && getBalance(root->left) < 0) {
        cout << "Rotation: Left-Right Rotation (LR)" << endl;
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && getBalance(root->right) <= 0) return rotateLeft(root);
    if (bf < -1 && getBalance(root->right) > 0) {
        cout << "Rotation: Right-Left Rotation (RL)" << endl;
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int main() {
    Node* root = NULL;

    int insertList[] = {50, 30, 70, 20, 40, 60, 80};
    int n1 = sizeof(insertList) / sizeof(insertList[0]);

    for (int i = 0; i < n1; i++) {
        root = insertNode(root, insertList[i]);
        cout << "Tre Height: " << getHeight(root) << endl;
    }

    int deleteList[] = {20, 70, 30};
    int n2 = sizeof(deleteList) / sizeof(deleteList[0]);

    for (int i = 0; i < n2; i++) {
        root = deleteNode(root, deleteList[i]);
        cout << "Tree Height: " << getHeight(root) << endl;
    }

}
