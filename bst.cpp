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
        else if (root->val > val) root->left = insertRec(root->left, val);
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
    void addIterative(int val) {
        if (root == NULL) root = new node(val);
        else {
            node* temp = root;
            while (1) {
                if (val == temp->val) break;
                else if (temp->val < val) {
                    if (temp->right == NULL) temp->addRight(val);
                    else temp = temp->right;
                }
                else {
                    if (temp->left == NULL) temp->addLeft(val);
                    else temp = temp->left;
                }
            }
        }
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
    bst.addIterative(15);
    bst.addIterative(1);
    bst.addIterative(5);
    bst.addIterative(3);
    bst.addIterative(8);

    bst.printInorder(); //1 3 5 8 15

    return 0;
}