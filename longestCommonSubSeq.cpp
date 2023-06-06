#include <iostream>
#include <vector>
using namespace std;


//Recursive Solution
int lcs(string &a,string &b,int i,int j){
    if(i==a.size() || j==b.size()) return 0;

    if(a[i]==b[j]) return 1+(lcs(a,b,i+1,j+1));
    return max(
        lcs(a,b,i,j+1),
        lcs(a,b,i+1,j)
    );
}

//DP Memoization Solution
int lcs(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
    if (i == a.size() || j == b.size()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans;
    if (a[i] == b[j]) ans = 1 + (lcs(a, b, i + 1, j + 1, dp));
    else ans = max(
        lcs(a, b, i, j + 1, dp),
        lcs(a, b, i + 1, j, dp)
    );

    return dp[i][j] = ans;
}

int main(){
    
    string a = "asd";
    string b = "aeisio";
    
    vector<vector<int>> dp(a.length(),vector<int>(b.length(),-1));

    cout<<"LCS recusive : "<<lcs(a,b,0,0)<<endl;
    cout<<"LCS DP Memo : "<<lcs(a,b,0,0,dp)<<endl;
    return 0;
}