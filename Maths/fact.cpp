#include <iostream>
using namespace std;

int fact(int n) {
    int f = 1;
    for (int i = n;i > 1;i--)
        f *= i;
    return f;
}

int main() {

    cout << "Enter no to find factorial of: ";
    int n;
    cin >> n;
    if (n < -1) {
        cout << "error";
        return 0;
    }

    cout << "Factorial of " << n << " is " << fact(n) << endl;

    return 0;
}