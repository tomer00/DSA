#include <iostream>
using namespace std;


class Stack {
    int size;
    int* st, point = -1;
public:
    Stack(int max) {
        size = max;
        st = new int[max];
    }
    bool push(int data) {
        point++;
        if (point == size) {
            point--;
            return false;
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
    cout << "Enter max size of stack : ";
    int n;
    cin >> n;
    Stack s(n);
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