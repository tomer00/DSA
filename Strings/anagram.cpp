#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int arr[26] = { 0 };
    int n = s.size();
    for (int i = 0;i < n;i++)
        arr[s[i] - 'a']++;

    n = t.size();
    for (int i = 0;i < n;i++)
        arr[t[i] - 'a']--;

    for (int i = 0;i < 26;i++) if (arr[i] > 0) return false;

    return true;

}

int main() {

    string s1, s2;
    cout << "Enter first String : ";
    cin >> s1;
    cout << "Enter second String : ";
    cin >> s2;

    cout<<(isAnagram(s1,s2)?"Strings are Anagram...":"Strings are not Anagrams...")<<endl;
    return 0;
}