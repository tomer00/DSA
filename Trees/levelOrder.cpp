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

void levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i = 0;i < n;i++) {
            Node* t = q.front();
            q.pop();
            if (t->left != NULL) q.push(t->left);
            if (t->right != NULL) q.push(t->right);
            level.push_back(t->data);
        }
        ans.push_back(level);

    }
    for (int i = 0;i < ans.size();i++) {
        for (int j = 0;j < ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
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

    levelOrder(root);

    return 0;
}