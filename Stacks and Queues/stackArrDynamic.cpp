#include <iostream>
using namespace std;


class Stack {
    int size = 2;
    int* st, point = -1;
public:
    Stack() {
        st = new int[size];
    }
    bool push(int data) {
        point++;
        if (point == size) {
            int* n = new int[size << 1];
            for (int i = 0;i < size;i++)
                n[i] = st[i];

            size <<= 1;
            delete st;
            st = n;
        }
        st[point] = data;
        return true;
    }
    int pop() {
        if (point == -1) return -1;
        int data = st[point--];
        return data;
    }
    int peek() {
        if (point == -1) return -1;
        return st[point];
    }
    bool isEmpty() {
        return point == -1;
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
}