#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class LList {
    Node* head = NULL;
public:
    Node* getHead() {
        return head;
    }
    void add(int val) {
        if (head == NULL) {
            head = new Node(val);
            return;
        }
        Node* n = new Node(val);

        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;

    }

    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool delVal(int val) {
        Node* temp = head;
        if (head->val == val) {
            head = head->next;
            delete temp;
            return true;
        }

        while (temp->next != NULL) {

            if (temp->next->val == val) {
                Node* t = temp->next;
                temp->next = t->next;
                delete t;
                return true;
            }

            temp = temp->next;
        }
        return false;
    }
    bool delLast() {
        if (head == NULL) return false;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return true;
        }
        Node* prev = head;
        Node* next = head->next;
        while (next->next != NULL) {
            prev = next;
            next = next->next;
        }
        delete next;
        prev->next = NULL;
        return true;
    }
    void revLL() {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

Node* revLL(Node* root) {
    Node* curr = root;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* getmid(Node* head) {
    Node* slow = head, * fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// checking if list is Palindrome
bool check(Node* head, Node* tail) {
    while (tail != NULL) {
        if (head->val != tail->val) return false;
        tail = tail->next;
        head = head->next;
    }
    return true;
}

// this function is to find the middle
bool isPalin(Node* head) {
    if (head == NULL || head->next == NULL) return true;

    Node* mid = getmid(head);
    Node* revList = reverse(mid->next);

    mid->next = revList;
    return check(head, revList);
}

int main() {

    LList ll;

    int c, val;
    printf("1 : Insert \n");
    printf("2 : Remove \n");
    printf("3 : Remove Last \n");
    printf("4 : Reverse\n");
    printf("5 : IsPalin\n");
    printf("6 : Print \n");
    do {
        printf("\nEnter operation no. : ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Enter val to Insert : ");
            scanf("%d", &val);
            ll.add(val);
            printf("Inserted : %d", val);
            break;
        case 2:
            printf("Enter val to Remove : ");
            cin >> val;
            cout << (ll.delVal(val) ? "Node deleted" : "Node not found");
            break;
        case 3:
            cout << (ll.delLast() ? "Deleted Last node.." : "Linked List have no node remaning...");
            break;
        case 4:
            ll.revLL();
            printf("Linked List Reversed");
            break;
        case 5:
            cout << (isPalin(ll.getHead()) ? "True" : "False");
            break;
        case 6:
            ll.print();
            break;
        }

    } while (c != -1);
    return 0;
}