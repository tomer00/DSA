#include <iostream>
#include <vector>
using namespace std;

int ma;

int lcs(string& a, string& b, int i, int j, vector<vector<int>>& dp) {
    if (i == a.size() || j == b.size()) return 0;
    
    int ans;
    if (a[i] == b[j]) ans = 1 + (lcs(a, b, i + 1, j + 1, dp));
    else ans = 0;
    ma = max(ma,ans);
    return dp[i][j] = ans ;
}

int main(){
    
    string a = "asd";
    string b = "asdio";
    
    vector<vector<int>> dp(a.length(),vector<int>(b.length(),0));
    lcs(a,b,0,0,dp);
    cout<<"LCSubString DP Memo : "<<ma<<endl; 
    return 0;
}