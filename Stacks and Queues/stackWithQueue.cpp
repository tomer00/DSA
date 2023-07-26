#include <iostream>
using namespace std;

class Queue {
    int size = 1;
    int* que, front = -1, rear = -1;
public:
    Queue() {
        que = new int[size];
    }
    bool enqueue(int data) {
        rear++;
        if (front == -1) {
            front = 0;
        }
        if (rear == size) {
            int* queN = new int[size << 1];
            for (int i = 0;i < size;i++) queN[i] = que[i];
            delete que;
            size <<= 1;
            que = queN;
        }
        que[rear] = data;
        return true;
    }
    int dequeue() {
        if (front == -1) return -1;
        if (front == rear) {
            int data = que[rear];
            front = rear = -1;
            return data;
        }
        return que[front++];
    }
    int peek() {
        if (front == -1) return -1;
        return que[front];
    }
    bool isEmpty() {
        return front == -1;
    }
};


class Stack {
    Queue q;
public:
    bool push(int data) {
        Queue t;
        while (!q.isEmpty()) t.enqueue(q.dequeue());
        q.enqueue(data);
        while (!t.isEmpty()) q.enqueue(t.dequeue());
        return true;
    }
    int pop() {
        return q.dequeue();
    }
    int peek() {
        return q.peek();
    }
    bool isEmpty() {
        return q.isEmpty();
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
    cout << "Stack is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "Poped element : " << s.pop() << endl;
    cout << "Stack is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    return 0;
    return 0;
}