#include <iostream>
using namespace std;

struct Node {
    int severity;
    int height;
    Node* left;
    Node* right;
    Node(int s) { severity = s; height = 1; left = right = NULL; }
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

Node* insertNode(Node* root, int severity) {
    if (!root) {
        cout << "Patient with severity " << severity << " admitted" << endl;
        return new Node(severity);
    }

    if (severity < root->severity) root->left = insertNode(root->left, severity);
    else if (severity > root->severity) root->right = insertNode(root->right, severity);
    else return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalance(root);
    
    if (bf > 1 && severity < root->left->severity) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Right Rotation" << endl;
        return rotateRight(root);
    }
    if (bf < -1 && severity > root->right->severity) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Left Rotation" << endl;
        return rotateLeft(root);
    }
    if (bf > 1 && severity > root->left->severity) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Left-Right Rotation" << endl;
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && severity < root->right->severity) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Right-Left Rotation" << endl;
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

Node* getMin(Node* n) {
    while (n->left) n = n->left;
    return n;
}

Node* getMax(Node* n) {
    if (!n) return NULL;
    while (n->right) n = n->right;
    return n;
}

Node* deleteNode(Node* root, int severity) {
    if (!root) return root;

    if (severity < root->severity) root->left = deleteNode(root->left, severity);
    else if (severity > root->severity) root->right = deleteNode(root->right, severity);
    else {
        cout << "Patient with severity " << severity << " discharged" << endl;
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
            root->severity = t->severity;
            root->right = deleteNode(root->right, t->severity);
        }
    }

    if (!root) return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bf = getBalance(root);
    
    if (bf > 1 && getBalance(root->left) >= 0) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Right Rotation" << endl;
        return rotateRight(root);
    }
    if (bf > 1 && getBalance(root->left) < 0) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Left-Right Rotation" << endl;
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (bf < -1 && getBalance(root->right) <= 0) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Left Rotation" << endl;
        return rotateLeft(root);
    }
    if (bf < -1 && getBalance(root->right) > 0) {
        cout << "Tree unbalanced at node " << root->severity << " (BF = " << bf << ")" << endl;
        cout << "Rotation: Right-Left Rotation" << endl;
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

int main() {
    Node* root = NULL;

    int arrivals[] = {50, 25, 75, 10, 30, 60, 80, 5, 15, 27, 90};
    int n1 = sizeof(arrivals) / sizeof(arrivals[0]);

    for (int i = 0; i < n1; i++) {
        root = insertNode(root, arrivals[i]);
        cout << "Tree Height: " << getHeight(root) << endl;
        Node* critical = getMax(root);
        if (critical) {
            cout << "Highest Severity Patient: " << critical->severity << endl;
        }
        cout << endl;
    }

    int discharges[] = {5, 10, 25, 90};
    int n2 = sizeof(discharges) / sizeof(discharges[0]);

    for (int i = 0; i < n2; i++) {
        root = deleteNode(root, discharges[i]);
        if (root) {
            cout << "Tree Height: " << getHeight(root) << endl;
            Node* critical = getMax(root);
            if (critical) {
                cout << "Highest Severity Patient: " << critical->severity << endl;
            }
        } else {
            cout << "No patients remaining" << endl;
        }
        cout << endl;
    }

    return 0;
}
