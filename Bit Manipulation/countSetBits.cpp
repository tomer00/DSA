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
//optimized
int countSetBitsO(int n) {
    int ans = 0;
    while (n) {
        n=n&(n-1);
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter no to count bits: ";
    cin >> n;
    cout << "No of set Bits in " << n << " is " << countSetBitsO(n) << endl;
    return 0;
}