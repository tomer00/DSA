#include <iostream>
using namespace std;


int countSetBits(int n) {
    int ans = 0;
    while (n) {
        if (n & 1) ans++;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter no to count bits: ";
    cin >> n;
    cout << "No of set Bits in " << n << " is " << countSetBits(n) << endl;
    return 0;
}