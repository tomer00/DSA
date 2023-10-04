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

class MinStack {
private:
    Stack s;
    int mini;
public:
    bool push(int val) {
        if (s.isEmpty()) {
            s.push(val);
            mini = val;
            return true;
        }

        if (val < mini) {
            s.push((val << 1) - mini);
            mini = val;
        }
        else s.push(val);

        return true;
    }
    int pop() {
        if (s.isEmpty()) return  -1;

        int curr = s.pop();
        if (curr > mini) return curr;
        int prevMin = mini;
        int v = (mini << 1) - curr;
        mini = v;
        return prevMin;
    }
    bool isEmpty() {
        return s.isEmpty();
    }
    int peek() {
        if (s.isEmpty()) return  -1;

        int curr = s.peek();
        return curr < mini ? mini : curr;
    }
    int getMin() {
        return s.isEmpty() ? -1 : mini;
    }
};
int main() {
    MinStack s;
    s.push(2);
    s.push(1);
    s.push(5);
    cout << "Min Element : " << s.getMin() << endl;
    cout << "Poped element : " << s.pop() << endl;
    cout << "Peek element : " << s.peek() << endl;
    cout << "Poped element : " << s.pop() << endl;
    cout << "Min Element : " << s.getMin() << endl;
    cout << "Stack is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "Poped element : " << s.pop() << endl;
    cout << "Stack is empty : " << (s.isEmpty() ? "true" : "false") << endl;
    cout << "Min Element : " << s.getMin() << endl;

    return 0;
}