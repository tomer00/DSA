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

void preOrder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {

    Node *root = new Node(1);

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

    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    return 0;
}