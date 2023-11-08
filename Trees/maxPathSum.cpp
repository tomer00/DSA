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



int findMax(Node *root,int &maxSum){
    if(!root) return 0;

    int ls = findMax(root->left,maxSum);
    int rs = findMax(root->right,maxSum);

    maxSum = max(maxSum,ls+rs+root->data);

    return root->data + max(ls,rs);
}


int maxPathSum(Node * root){
    int maxSum=0;
    findMax(root,maxSum);
    return maxSum;
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
    cout <<"Max Path Sum of tree is : "<< maxPathSum(root) << endl;

    return 0;
}