#include <iostream>
using namespace std;

int decimal(string& n) {
    if (n.size() < 1) return 0;
    int ans = 0;
    int mul = 1;
    for (int i = n.size() - 1;i > -1;i--) {
        if (n[i] == '1')
            ans += mul;
        mul <<= 1;
    }
    return ans;
}

int main() {

    cout << "Enter no to change to Decimal: ";
    string n;
    cin >> n;
    cout << "Decimal is: " << decimal(n) << endl;
    return 0;
}
