#include <iostream>
using namespace std;


class Stack {
    int size;
    int* st, p1 = -1, p2;
public:
    Stack(int max) {
        size = max;
        st = new int[max];
        p2 = size;
    }
    bool push1(int data) {
        p1++;
        if (p1 == p2) {
            p1--;
            return false;
        }
        st[p1] = data;
        return true;
    }
    bool push2(int data) {
        p2--;
        if (p2 == p1) {
            p2++;
            return false;
        }
        st[p2] = data;
        return true;
    }
    int pop1() {
        if (p1 == -1) return -1;
        int data = st[p1--];
        return data;
    }
    int pop2() {
        if (p2 == size) return -1;
        int data = st[p2++];
        return data;
    }
    int peek1() {
        if (p1 == -1) return -1;
        return st[p1];
    }
    int peek2() {
        if (p2 == size) return -1;
        return st[p2];
    }
    bool isEmpty() {
        return p1 == -1 && p2 == size;
    }
};
int main() {
    cout << "Enter max size of stack : ";
    int n;
    cin >> n;
    Stack s(n);
    s.push1(2);
    s.push2(1);
    s.push1(5);
    s.push2(6);
    s.push1(14);
    cout << "Poped element : " << s.pop1() << endl;
    cout << "Poped element : " << s.pop1() << endl;
    cout << "Peek element : " << s.peek2() << endl;
    cout << "Poped element : " << s.pop2() << endl;
    cout << "Poped element : " << s.pop2() << endl;
    cout << "Stack is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "Poped element : " << s.pop1() << endl;
    cout << "Stack is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    return 0;
}