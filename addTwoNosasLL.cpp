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

node* revLL(node* root) {
    if (root == NULL || root->next == NULL) return root;
    node* prev = NULL;
    node* curr = root;
    node* forward = root->next;
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

//Approach 2
//optimized
node* sumLL2(node* f, node* s) {
    // revese both LL
    f = revLL(f);
    s = revLL(s);
    node* nLL;
    int carr = 0;
    int sum = f->data + s->data;
    nLL = new node(sum % 10);
    carr = sum / 10;
    f = f->next;
    s = s->next;
    node* t = nLL;
    while (f != NULL && s != NULL) {
        sum = f->data + s->data + carr;
        nLL->next = new node(sum % 10);
        carr = sum / 10;
        f = f->next;
        s = s->next;
        nLL = nLL->next;
    }

    f = f == NULL ? s : f;
    while (f != NULL) {
        sum = f->data + carr;
        nLL->next = new node(sum % 10);
        carr = sum / 10;
        f = f->next;
        nLL = nLL->next;
    }
    return revLL(t);
}
//taking input as string for a very long number
node* stringTOLL(string& no) {
    int nn = no.size();
    if (nn == 1)
        return new node(no[0] - '0');

    node* n = new node(no[0] - '0');
    node* t = n;

    for (int i = 1;i < nn;i++) {
        t->next = new node(no[i] - '0');
        t = t->next;
    }

    return n;
}

int main() {

    // int n1, n2, n3 = 0;
    cout << "Enter Two Numbers to add : ";
    // cin >> n1 >> n2;

    // node* firstLL = numberToLL(n1);
    // node* secondLL = numberToLL(n2);

    string n1, n2;
    cin>>n1>>n2;
    node* firstLL = stringTOLL(n1);
    node* secondLL = stringTOLL(n2);

    printLL(firstLL);
    printLL(secondLL);

    printLL(sumLL2(firstLL, secondLL));

    return 0;
}