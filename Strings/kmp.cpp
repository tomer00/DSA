#include <iostream>
using namespace std;

int kmpSearch(string& txt, string& pat) {

    int i = 0, j = 0;
    int n = txt.size(), m = pat.size();

    int index = 0;

    while (i < n && j < m) {
        if (txt[i] == pat[j]) {
            ++i;
            ++j;
        }
        else {
            ++index;
            i = index;
            j = 0;
        }
    }
    return index == n ? -1 : index;
}

int main()
{

    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    cout << "Found at index : " << kmpSearch(txt, pat) << endl;

    return 0;
}
