#include <iostream>
#include <queue>
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

void topView(Node* root){
    vector<int> ans;
    if(!root) return;
    map<int,int> mp;

    queue<pair<Node * ,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        auto n = it.first;
        int line = it.second;

        if(mp.find(line)==mp.end()) mp[line]=n->data;

        if(n->left)q.push({n->left,line-1});
        if(n->right)q.push({n->right,line+1});
    }


    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
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

    topView(root);

    return 0;
}