#include <iostream>
#include <vector>
using namespace std;

vector<char> dupliChars(string& s) {

    int arr[26] = { 0 };
    int n = s.size();
    for (int i = 0;i < n;i++)
        arr[s[i] - 'a']++;

    vector<char> ans;

    for (int i = 0;i < 26;i++) if (arr[i] > 1) ans.push_back('a' + i);

    return ans;

}

int main() {


    string s;
    cout << "Enter String : ";
    cin >> s;


    cout << "Duplicate Chars are : ";
    for (char c : dupliChars(s)) cout << c << ' ';
    cout << endl;

    return 0;
}