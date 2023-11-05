#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }

    void addLeft(int val) {
        if (left == NULL) {
            left = new Node(val);
            return;
        }
        left->data = val;
    }
    void addRight(int val) {
        if (right == NULL) {
            right = new Node(val);
            return;
        }
        right->data = val;
    }
};

int height(Node* root, int& dia) {
    if (!root) return 0;
    int lh = height(root->left, dia);
    int rh = height(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh , rh);
}

int diaMeter(Node* root) {
    int dia = 0;
    height(root,dia);
    return dia;
}

int main() {

    Node* root = new Node(1);

    root->addLeft(2);
    root->addRight(2);
    root->left->addLeft(3);
    root->left->addRight(4);
    root->right->addLeft(4);
    root->right->addRight(3);
    root->right->right->addRight(10);
    root->right->right->right->addRight(11);
    root->right->right->right->right->addRight(12);
    root->right->right->right->right->right->addRight(14);
    cout << diaMeter(root) << endl;

    return 0;
}