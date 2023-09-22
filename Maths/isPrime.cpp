#include <iostream>
#include <math.h>
using namespace std;

//using for loop not recomended
bool isPrime(int no) {
    if(no<2) return false;
    int n = sqrt(no) + 1;
    for (int i = 2;i < n;i++) {
        if (no % i == 0)return false;
    }
    return true;
}


int main() {
    cout << "Enter no to check for ArmStrong: ";
    int no;
    cin >> no;
    cout << no << (isPrime(no) ? " is a Prime..." : " is not a Prime...") << endl;
    return 0;
}