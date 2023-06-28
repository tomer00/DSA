#include <iostream>
using namespace std;


class node {
public:
    int val;
    node* left, * right;
    void addLeft(int val) {
        left = new node(val);
    }
    void addRight(int val) {
        right = new node(val);
    }
    node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class BST {
    node* root = NULL;
    node* insertRec(node* root, int val) {
        if (root == NULL) return new node(val);
        if (root->val < val) root->right = insertRec(root->right, val);
        else root->left = insertRec(root->left, val);
        return root;
    }
    void inorder(node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
public:
    void add(int val) {
        this->root = insertRec(root, val);
    }
    bool del(int val) {
    }
    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {

    BST bst;
    bst.add(15);
    bst.add(1);
    bst.add(5);
    bst.add(3);
    bst.add(8);

    bst.printInorder(); //1 3 5 8 15

    return 0;
}