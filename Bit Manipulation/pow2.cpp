#include <iostream>
using namespace std;

bool isPow(int n) {
    n = n & (n - 1);
    return n == 0;
}

int main() {

    int n;
    cout << "Enter a no to check if it is a power of 2: ";
    cin >> n;
    cout << (isPow(n) ? "It is power of 2" : "Not power of 2") << endl;

    return 0;
}