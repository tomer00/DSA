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