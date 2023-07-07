#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data = 0;
    Node* next;
    Node(int val) {
        this->data = val;
    }
};

class LL {
public:
    Node* root = NULL, * lastNode = NULL;
    void addNode(int val) {
        if (root == NULL) {
            root = new Node(val);
            lastNode = root;
            return;
        }
        lastNode->next = new Node(val);
        lastNode = lastNode->next;
    }
    int countUnique() {
        Node* t = root;
        int ans = 0;
        unordered_map<int,int> m;
        while (t != NULL) {
            if(m[t->data]==0){
                m[t->data] = 1;
                ans++;
            }
            t=t->next;
        }
        return ans;
    }
};


int main() {
    cout << "Enter size of List : ";
    int n;
    LL* l1 = new LL();
    cin >> n;
    cout << "Enter " << n << " elements :";
    for (int i = 0;i < n;i++) {
        int n;
        cin >> n;
        l1->addNode(n);
    }
    cout << l1->countUnique() << endl;
    return 0;
}