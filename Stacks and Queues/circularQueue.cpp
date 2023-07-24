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
            que[rear] = data;
            front++;
            return true;
        }
        if ((rear % size) == front) {
            rear--;
            return false;
        }
        que[rear % size] = data;
        return true;
    }
    int dequeue() {
        if (front == -1) return -1;
        if ((front % size) == rear) {
            int data = que[rear];
            front = rear = -1;
            return data;
        }
        return que[front++ % size];
    }
    int peek() {
        if (front == -1) return -1;
        return que[front];
    }
    bool isEmpty() {
        return front == -1;
    }
    void print(){
        for(int i = 0;i<size;i++) cout<<que[i]<<" ";
        cout<<endl;
    }
};
int main() {
    cout << "Enter max size of Queue : ";
    int n;
    cin >> n;
    Queue q(n);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(5);
    q.print();
    cout << "Dequeued element : " << q.dequeue() << endl;
    cout << "Peek element : " << q.peek() << endl;
    cout << "Dequeued element : " << q.dequeue() << endl;
    cout << "Queue is empty : " << (q.isEmpty() ? "true" : "false") << endl;
    cout << "Dequeued element : " << q.dequeue() << endl;
    cout << "Queue is empty : " << (q.isEmpty() ? "true" : "false") << endl;
    return 0;
}