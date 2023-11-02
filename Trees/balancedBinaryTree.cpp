#include <iostream>
using namespace std;

class Node {
public:
    Node* left, * right;
    int data;
    Node(int d) {
        data = d;
        left = right = NULL;
    }

    void addRight(int data) {
        if (right == NULL) {
            right = new Node(data);
        }
        else right->data = data;
    }
    void addLeft(int data) {
        if (left == NULL) {
            left = new Node(data);
        }
        else left->data = data;
    }
};

int hei(Node* root) {
    if (root == NULL) return 0;
    int lh = hei(root->left);
    int rh = hei(root->right);

    if (lh == -1 || rh == -1) return -1;
    if (abs(lh - rh) > 1) return-1;

    return max(lh, rh) + 1;
}

bool isBalanced(Node* root) {
    return hei(root) != -1;
}

int main() {

    Node* root = new Node(1);

    root->addLeft(2);
    root->addRight(2);

    root->left->addLeft(3);
    root->right->addLeft(4);
    root->left->addRight(4);
    root->right->addRight(3);

    root->right->left->addLeft(6);
    root->right->left->addRight(7);
    root->right->addRight(8);
    root->right->right->addLeft(9);
    root->right->right->addRight(10);


    cout << (isBalanced(root)?"Tree is Balanced Binary Tree":"Tree is Not a Balanced Binary Tree") << endl;

    return 0;
}