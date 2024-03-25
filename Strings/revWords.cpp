#include <iostream>
using namespace std;

string revWords(string& str) {
    string ret = "";
    int j = str.size() - 1;
    int i;
    for (int i = str.size() - 1;i > -1;--i) {
        if (str[i] == ' ') {
            int k = i;
            while (k <= j) {
                ret += str[k++];
            }
            j = i;
            i--;
        }
    }
    i=0;
    while (i <= j) {
        ret += str[i++];
    }
    return ret;
}

int main()
{

    string txt = "i like this program very much";
    cout << revWords(txt) << endl;
    return 0;
}
