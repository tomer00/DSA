#include <iostream>
#include <stack>
using namespace std;

string binary(int n) {
    if (n < 1) return "not a valid no";
    stack<char> s;
    while (n) {
        s.push((n % 2) + '0');
        n >>= 1;
    }
    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}


int main() {
    cout << "Enter no to change to binary: ";
    int n;
    cin >> n;
    cout << "Binary is: " << binary(n) << endl;
    return 0;
}