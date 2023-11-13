#include <iostream>
#include <queue>
#include <vector>
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

bool isLeaf(Node* root) {
    return !root->left && !root->right;
}

void getLeftBoundary(Node* root, vector<int>& a) {
    Node* node = root->left;
    while (node) {
        if (!isLeaf(node)) a.push_back(node->data);
        if (node->left) node = node->left;
        else node = node->right;
    }
}
void getLeaves(Node* root, vector<int>& a) {
    if (isLeaf(root)) {
        a.push_back(root->data);
        return;
    }
    if (root->left) getLeaves(root->left, a);
    if (root->right) getLeaves(root->right, a);
}
void getRightBoundary(Node* root, vector<int>& a) {
    Node* node = root->right;
    vector<int> temp;
    while (node) {
        if (!isLeaf(node)) temp.push_back(node->data);
        if (node->right) node = node->right;
        else node = node->left;
    }

    for (int i = temp.size() - 1;i > -1;i--) {
        a.push_back(temp[i]);
    }
}

void boundaryTraversal(Node* root) {
    vector<int> ans;

    getLeftBoundary(root, ans);
    getLeaves(root, ans);
    getRightBoundary(root, ans);

    for (int j = 0;j < ans.size();j++)
        cout << ans[j] << " ";
}

int main() {

    Node* root = new Node(1);

    root->addLeft(2);
    root->addRight(3);

    root->left->addLeft(4);
    root->right->addLeft(5);
    root->left->addRight(6);
    root->right->addRight(7);

    root->right->left->addLeft(8);
    root->right->left->addRight(9);
    root->right->addRight(10);
    root->right->right->addLeft(11);
    root->right->right->addRight(12);

    boundaryTraversal(root);

    return 0;
}