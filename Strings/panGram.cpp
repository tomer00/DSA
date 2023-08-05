#include <iostream>
#include <vector>
using namespace std;

bool panGram(string& str) {
    vector<int> v(26, 0);
    for (auto c : str) {
        int ind = c - 'a';
        if (ind < 0) ind += 32;
        v[ind]++;
    }
    for (auto i : v) if (i < 1) return false;
    return true;
}

int main() {

    string s1;
    cout << "Enter your String : ";
    cin >> s1;

    cout << (panGram(s1) ? "String is PanGram..." : "String is not PanGram...") << endl;
    return 0;
}