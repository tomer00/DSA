#include <iostream>
using namespace std;


bool* createSieve(int max) {
    bool * arr = new bool[max];
    arr[0] = arr[1] = 1;
    for (int i = 2;i < 101;i++) {
        if (arr[i] == 1)continue;
        for (int j = i * i;j < 101;j += i)
            arr[j] = 1;
    }
    return arr;
}
bool isSP(int n) {
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    return false;
}
bool isIndiPrime(int no) {
    while (no) {
        if (!isSP(no % 10)) return false;
        no /= 10;
    }
    return true;
}

int countSuperPrime(int left, int right) {
    bool *arr = createSieve(right+1);
    int ans = 0;
    for (int i = left;i <= right;i++) {
        if (!arr[i] && isIndiPrime(i)) ans++;
    }
    return ans;
}

int main() {
    cout << "Enter left and right bound: ";
    int left, right;
    cin >> left >> right;
    cout << "Total no of SuperPrimes in range is : " << countSuperPrime(left, right) << endl;
    return 0;
}