#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX  __INT_MAX__
#define INT_MIN  (-INT_MAX - 1)

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
void inorder(Node* root, vector<int>& list) {
    if (root == NULL) return;
    inorder(root->left, list);
    list.push_back(root->data);
    inorder(root->right, list);
}
//#Approach 1
//checking if inorder is sorted
bool isValBst1(Node* root) {
    vector<int> vV;
    inorder(root, vV);
    bool isSorted = true;
    int n = vV.size();
    for (int i = 1;i < n;i++) {
        if (vV[i] <= vV[i - 1]) {
            isSorted = false;
            break;
        }
    }
    return isSorted;
}
//#Approach 2
//checking if node childrens are valid
bool isValBst2(Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= max && root->data >= min) {
        bool left = isValBst2(root->left, min, root->data);
        bool right = isValBst2(root->right, root->data, max);
        return left && right;
    }
    else return false;
}
//#Approach 2
//checking BST properties for each node
bool isValBst3(Node* root) {
    if (root == NULL) return true;
    // Recursively check if both the left and right subtrees are valid BSTs
    if (isValBst3(root->left) && isValBst3(root->right)) {
        // Check the BST property for the current node
        bool left = root->left == NULL || root->left->data < root->data;
        bool right = root->right == NULL || root->right->data > root->data;

        // Return true if both left and right subtrees satisfy the BST property
        return left && right;
    }
    else return false;
}

int main() {
    //initializing trees
    Node* valTree = new Node(5);
    valTree->addLeft(2);
    valTree->addRight(8);
    valTree->right->addLeft(7);
    valTree->right->addRight(10);

    Node* invalTree = new Node(2);
    invalTree->addLeft(1);
    invalTree->addRight(3);
    invalTree->left->addLeft(5);
    invalTree->left->addRight(7);

    // cout << "Valid bst : " << (isValBst2(valTree, INT_MIN, INT_MAX) ? "True" : "False") << endl;
    // cout << "Valid bst : " << (isValBst2(invalTree, INT_MIN, INT_MAX) ? "True" : "False") << endl;
    cout << "Valid bst : " << (isValBst3(valTree) ? "True" : "False") << endl;
    cout << "Valid bst : " << (isValBst3(invalTree) ? "True" : "False") << endl;

    return 0;
}