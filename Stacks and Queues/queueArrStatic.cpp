#include <iostream>
using namespace std;


class Queue {
    int size;
    int* que, front = -1, rear = -1;
public:
    Queue(int max) {
        size = max;
        que = new int[max];
    }
    bool enqueue(int data) {
        rear++;
        if (front == -1) {
            front = 0;
        }
        if (rear == size) {
            rear--;
            return false;
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
    cout << "Enter max size of Queue : ";
    int n;
    cin >> n;
    Queue s(n);
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