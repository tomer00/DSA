#include <iostream>
using namespace std;

int cube(int n) {
    return n * n * n;
}

bool isArmStrong(int no) {
    if(no<10) return true;
    int ans = 0;
    int n = no;
    while (n) {
        ans += cube(n % 10);
        n /= 10;
    }
    return ans == no;
}
int main() {

    cout << "Enter no to check for ArmStrong: ";
    int no;
    cin >> no;
    cout << no << (isArmStrong(no) ? " is an ArmStorng..." : " is not an ArmStrong...") << endl;
    return 0;
}