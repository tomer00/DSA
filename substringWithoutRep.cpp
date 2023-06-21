#include <iostream>
#include <string>
#include <vector>
using namespace std;


//sliding window approach
//Time = O(n)
//Space = O(1)
int solve(string& str) {
    vector<bool> v(26, false);
    int ans = -1;
    int n = str.length();
    int i = 0, j = 0;
    while (i <= j && j < n) {
        char cj = str[j];
        char ci = str[i];
        if (v[cj - 'a']) {
            i++;
            v[ci - 'a'] = false;
        }
        else {
            ans = max(ans,j-i);
            v[cj - 'a'] = true;
            j++;
        }
    }
    return ans+1;

}
int main() {

    string str = "abbacdabde";
    cout << solve(str) << endl; //ans = 4


    return 0;
}