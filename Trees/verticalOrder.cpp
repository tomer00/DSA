#include <iostream>
#include <set>
#include <vector>
#include <map>
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

void verti(Node* root, map<int, map<int, set<int>>>& ans, int v, int h) {
    if (!root) return;
    verti(root->left, ans, v + 1, h - 1);
    verti(root->right, ans, v + 1, h + 1);
    ans[h][v].insert(root->data);
}

void verticalOrder(Node* root) {
    map<int, map<int, set<int>>> ans;
    verti(root,ans,0,0);
    for (auto i : ans) {
        for (auto j : i.second) {
            for (auto k : j.second) {
                cout << " " << k;
            }
        }
        cout << endl;
    }
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

    verticalOrder(root);

    return 0;
}