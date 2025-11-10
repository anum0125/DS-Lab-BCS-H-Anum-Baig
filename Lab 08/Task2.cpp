#include <iostream>
#include <string>
using namespace std;

class song {
public:
    string name;
    int playCount;
    song* left;
    song* right;

    song(string n, int p) {
        name = n;
        playCount = p;
        left = right = NULL;
    }
};

void insert(song*& root, string name, int playCount) {
    if (root == NULL) {
        root = new song(name, playCount);
        return;
    }
    if (playCount < root->playCount)
        insert(root->left, name, playCount);
    else if (playCount > root->playCount)
        insert(root->right, name, playCount);
}

void search(song* root, int playCount) {
    if (root == NULL) {
        cout << "Not found!" << endl;
        return;
    }
    if (root->playCount == playCount) {
        cout << "Song Name: " << root->name << endl;
        return;
    }
    if (playCount < root->playCount)
        search(root->left, playCount);
    else
        search(root->right, playCount);
}

void inOrder(song* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->name << " (" << root->playCount << ")" << endl;
    inOrder(root->right);
}

void postOrder(song* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->name << " (" << root->playCount << ")" << endl;
}

song* findMin(song* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

song* deleteSong(song* root, int playCount) {
    if (root == NULL) return NULL;

    if (playCount < root->playCount)
        root->left = deleteSong(root->left, playCount);
    else if (playCount > root->playCount)
        root->right = deleteSong(root->right, playCount);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            song* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            song* temp = root->left;
            delete root;
            return temp;
        }
        else {
            song* temp = findMin(root->right);
            root->name = temp->name;
            root->playCount = temp->playCount;
            root->right = deleteSong(root->right, temp->playCount);
        }
    }
    return root;
}

int main() {
    song* root = NULL;

    insert(root, "The Last GoodBye", 50);
    insert(root, "I See Fire", 30);
    insert(root, "Chiquitita", 70);

    cout << "Inorder (least → most played): " << endl;
    inOrder(root);
    cout << "Postorder (reverse popularity order): " << endl;
    postOrder(root);

    cout << "Searching for play count 30: " << endl;
    search(root, 30);
    cout << "Deleting song with play count 50: " << endl;
    root = deleteSong(root, 50);
    cout << "Inorder after deletion: " << endl;
    inOrder(root);

}


    
