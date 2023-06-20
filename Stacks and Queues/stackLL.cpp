#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;
    Node(int data) {
        this->data = data;
    }
};
class Stack {
    int size = 0;
    Node* head = NULL;
public:
    bool push(int data) {
        if (head == NULL) {
            head = new Node(data);
            size++;
            return true;
        }
        Node* t = new Node(data);
        t->next = head;
        head = t;
        size++;
        return true;
    }
    int pop() {
        if (size == 0) return -1;
        size--;
        Node* t = head;
        head = head->next;
        int data = t->data;
        delete t;
        return data;
    }
    int peek() {
        if (size == 0) return -1;
        return head->data;
    }
    bool isEmpty() {
        return size == 0;
    }
};
int main() {
    Stack s;
    s.push(2);
    s.push(1);
    s.push(5);
    cout << "Poped element : " << s.pop() << endl;
    cout << "Peek element : " << s.peek() << endl;
    cout << "Poped element : " << s.pop() << endl;
    cout << "Stack is empty : " << (s.isEmpty()?"true" : "false") << endl;
    cout << "Poped element : " << s.pop() << endl;
    cout << "Stack is empty : " << (s.isEmpty()?"true" : "false") << endl;
    return 0;
}