#include <iostream>
using namespace std;

bool isEven(int n) {
    return n % 2 == 0;
}
int main() {
    int n;
    do {
        cout << "Enter no to check for Even Odd : ";
        cin >> n;
        cout << (isEven(n) ? "Even no" : "Odd no") << endl;
    } while (n != -1);
    return 0;
}