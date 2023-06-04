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

int treeHeight(Node* root) {
    if (root == NULL) return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}


pair<int, int> diaFast(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }
    pair<int, int> p = make_pair(0, 0);

    pair<int, int> left = diaFast(root->left);
    pair<int, int> right = diaFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    p.first = max(max(op1, op2), op3);
    p.second = max(left.second, right.second) + 1;

    return p;

}

int diaMeter(Node* root) {
    return diaFast(root).first;
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

    cout << treeHeight(root) << endl;
    cout << diaMeter(root) << endl;

    return 0;
}