#include<iostream>

using namespace std;

class Fraction {
    int num, deno;
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

public:
    Fraction(int n, int d) {
        num = n;
        deno = d;
    }
    void add(int n, int d) {
        int l = lcm(deno, d);
        num = (num * (l / deno)) + (n * (l / d));
        deno = l;
        simplify();
        print();
    }
    void sub(int n, int d) {
        int l = lcm(deno, d);
        num = (num * (l / deno)) - (n * (l / d));
        deno = l;
        simplify();
        print();
    }
    void multi(int n, int d) {
        num *= n;
        deno *= d;
        simplify();
        print();
    }

    void print() {
        if(num==0) cout << '0' << endl;
        else cout << num << '/' << deno << endl;
    }
    void simplify() {
        int g = gcd(num, deno);
        num /= g;
        deno /= g;
    }

};

int main() {

    cout << "Enter num and denominator : ";
    int num, deno;
    cin >> num >> deno;

    Fraction f(num, deno);


    int q, n, d;
    cout << "Opertaions::->\n1 Addition\n2 Multiplication\n3 Subtraction\n0 Quit\n";

    while(true) {
        cout << "Select operation from abive menu : ";
        cin >> q;
        if(q==0) break;
        cout << "Enter num and denominator : ";
        cin >> n >> d;
        switch (q) {
        case 1:
            f.add(n, d);
            break;
        case 2:
            f.multi(n, d);
            break;
        case 3:
            f.sub(n, d);
            break;
        }
    }

    return 0;
}