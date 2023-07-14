#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void printLL(node* root) {
    while (root != NULL) {
        cout << root->data;
        root = root->next;
    }
    cout << endl;
}
node* numberToLL(int val) {
    if (val < 0) return NULL;
    stack<int> s;
    while (val) {
        s.push(val % 10);
        val /= 10;
    }
    node* head = new node(s.top());
    node* t = head;
    s.pop();
    while (!s.empty()) {
        t->next = new node(s.top());
        s.pop();
        t = t->next;
    }
    return head;
}

int numberFromLL(node* root) {
    if (root == NULL) return 0;
    stack<int> s;
    while (root != NULL) {
        s.push(root->data);
        root = root->next;
    }

    int mul = 1;
    int ans = 0;

    while (!s.empty()) {
        ans += s.top() * mul;
        s.pop();
        mul *= 10;
    }
    return ans;
}
//Approach 1
node* sumLL(node* f, node* s) {
    //convert it to int first and then add
    int n1 = numberFromLL(f);
    int n2 = numberFromLL(s);

    return numberToLL(n1 + n2);
}

int main() {

    int n1, n2, n3 = 0;
    cout << "Enter Two Numbers to add : ";
    cin >> n1 >> n2;

    node* firstLL = numberToLL(n1);
    node* secondLL = numberToLL(n2);

    printLL(firstLL);
    printLL(secondLL);

    printLL(sumLL(firstLL,secondLL));

    return 0;
}