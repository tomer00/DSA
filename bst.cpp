#include <iostream>
using namespace std;


class node {
    int val;
    node* left, * right;
public:
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
    node* root;
public:
    void add(int val) {
        if (root == NULL) root = new node(val);
        else {

        }
    }
    bool del(int val) {
        
    }
};

int main() {
    return 0;
}