#include <iostream>
using namespace std;


bool isPalind(string& s) {
    int l = 0;
    int h = s.size() - 1;
    while (l < h)
        if (s[l++] != s[h--]) return false;
    return true;
}
int main() {

    string str;
    cout << "Enter word to check for plaindrome : ";
    cin >> str;

    cout << (isPalind(str) ? "Valid Palindrome...." : "Invalid Palindrome....") << endl;

    return 0;
}