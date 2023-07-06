#include <iostream>
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
            lastNode=root;
            return;
        }
        lastNode->next = new Node(val);
        lastNode = lastNode->next;
    }
};

LL * mergeLL(LL *l1,LL *l2){
    LL *n = new LL();
    Node *t1=l1->root,*t2=l2->root;
    while(t1!=NULL && t2!=NULL){
        if(t1->data<t2->data) {
            n->addNode(t1->data);
            t1=t1->next;
        }else{
            n->addNode(t2->data);
            t2=t2->next;
        }
    }
    while(t1!=NULL){
            n->addNode(t1->data);
            t1=t1->next;
    }
    while(t2!=NULL){
            n->addNode(t2->data);
            t2=t2->next;
    }
    return n;
}

int main() {

    cout << "Enter size of List 1 and 2 : ";
    int n1, n2;
    LL *l1=new LL();
    LL *l2=new LL();
    cin >> n1 >> n2;
    cout << "Enter " << n1 << " ascending elements of l1 :";
    for (int i = 0;i < n1;i++) {
        int n;
        cin >> n;
        l1->addNode(n);
    }

    cout << "Enter " << n2 << " ascending elements of l2 :";
    for (int i = 0;i < n2;i++) {
        int n;
        cin >> n;
        l2->addNode(n);
    }

    LL* merged = mergeLL(l1,l2);
    
    Node *t = merged->root;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }

    cout << endl;

    return 0;
}