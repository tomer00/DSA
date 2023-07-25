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
    ~Stack() {
        while (!isEmpty()) pop();
    }
};


class Queue {
private: Stack s;
public:
    bool enqueue(int data) {
        Stack s1;
        while (!s.isEmpty()) s1.push(s.pop());
        s.push(data);
        while (!s1.isEmpty()) s.push(s1.pop());
        return true;
    }
    int dequeue() {
        if (s.isEmpty()) return -1;
        return s.pop();
    }
    int peek() {
        return s.peek();
    }
    bool isEmpty() {
        return s.isEmpty();
    }

};

int main() {

    Queue s;
    s.enqueue(2);
    s.enqueue(1);
    s.enqueue(5);
    cout << "Dequeued element : " << s.dequeue() << endl;
    cout << "Peek element : " << s.peek() << endl;
    cout << "Dequeued element : " << s.dequeue() << endl;
    cout << "Queue is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "Dequeued element : " << s.dequeue() << endl;
    cout << "Queue is empty : " << (s.isEmpty() ? "true" : "false") << endl;

    return 0;
}