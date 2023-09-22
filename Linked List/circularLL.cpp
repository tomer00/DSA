#include <iostream>
using namespace std;
class Node {
public:
    Node(int val) {
        data = val;
        next = NULL;
    }
    int data;
    Node* next;
};

class CircularLL {
private:
    Node* curr = NULL;
public:
    void addNode(int val) {
        if (curr == NULL) {
            curr = new Node(val);
            curr->next = curr;
        }
        else {
            Node* t = curr->next;
            Node* n = new Node(val);
            n->next = t;
            curr->next = n;
        }
    }
    bool delNode(int val) {
        if (curr == NULL) return false;
        if (curr->data == val) {
            curr = NULL;
            return true;
        }
        Node* temp = curr->next;
        while (temp != curr) {

            if (temp->data == val) {
                Node* t = temp->next;
                if (temp == curr)
                    curr = temp->next;
                temp->next = t->next;
                delete t;
                return true;
            }

            temp = temp->next;
        }
        return false;
    }
    int forward() {
        if (curr != NULL) {
            curr = curr->next;
            return curr->data;
        }
        return -1;
    }
    int backward() {
        if (curr != NULL) {
            Node* i = curr;
            while (i->next != curr) {
                i = i->next;
            }
            curr = i;
            return curr->data;
        }
        return -1;
    }
    void printList() {
        if (curr != NULL) {
            if (curr->next == curr) cout << curr->data << endl;
            else {
                Node* i = curr;
                while (i->next != curr) {
                    cout << i->data << " ";
                    i = i->next;
                }
                cout <<i->data<<endl;
            }
        }

    }
};

int main() {

    CircularLL ll;

    int c, val;
    printf("1 : Insert \n");
    printf("2 : Remove \n");
    printf("3 : Forward \n");
    printf("4 : Backward \n");
    printf("5 : Print \n");
    do {
        printf("\nEnter operation no. : ");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Enter val to Insert : ");
            scanf("%d", &val);
            ll.addNode(val);
            printf("Inserted : %d", val);
            break;
        case 2:
            printf("Enter val to Remove : ");
            cin >> val;
            cout << (ll.delNode(val) ? "Node deleted" : "Node not found");
            break;
        case 3:
            cout << "Current pointer moved to: " << ll.forward();
            break;
        case 4:
            cout << "Current pointer moved to: " << ll.backward();
            break;
        case 5:
            ll.printList();
            break;
        }

    } while (c != -1);
    return 0;
}
