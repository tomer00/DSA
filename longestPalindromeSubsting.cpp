#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string& str, int i, int j) {
    while (i <= j)
        if (str[i++] != str[j--]) return false;
    return true;
}
//bruteForce check for all substrings
//Time O(n^3)
int solve(string& str) {
    int ans = 0;
    int n = str.length();
    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            if (isPalindrome(str, i, j)) ans = max(ans, j - i);
        }
    }
    return ans + 1;
}

//Time O(n^2)
int solve2(string& str) {
    int ans = 0;
    int n = str.length() - 1;
    if (n == 0) ans = 1;
    else if (n == 1) ans = (str[0] == str[1]) ? 2 : 1;
    for (int i = 1;i < n;i++) {
        int l = i - 1;
        int h = i + 1;
        if (str[i] == str[l] && str[i] == str[h]) {
            l--;h++;
        }
        else if (str[i] == str[l]) h--;
        else if (str[i] == str[h]) l++;

        while (l > -1 && h <= n) {
            if (str[l] != str[h]) break;
            l--;
            h++;
        }
        ans = max(ans, h - l - 1);
    }
    return ans;
}

int main() {

    string str = "asddsa";
    cout << solve2(str) << endl;

    return 0;
}