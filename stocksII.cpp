#include <iostream>
#include <vector>
using namespace std;

//Recursive Solution without DP
int maxProfit(int* arr, int n, int i, bool canBuy) {

    if (i == n) return 0;
    int profit = 0;
    if (canBuy)
        profit = max(-arr[i] + maxProfit(arr, n, i + 1, false), maxProfit(arr, n, i + 1, true));
    else profit = max(arr[i] + maxProfit(arr, n, i + 1, true), maxProfit(arr, n, i + 1, false));

    return profit;
}

//Solutoin with DP memoization
int maxProfitDP(int* arr, int n, int i, bool canBuy, vector<vector<int>> &dp) {

    if (i == n) return 0;
    if(dp[i][canBuy]!=-1) return dp[i][canBuy];
    int profit = 0;
    if (canBuy)
        profit = max(-arr[i] + maxProfitDP(arr, n, i + 1, false,dp), maxProfitDP(arr, n, i + 1, true,dp));
    else profit = max(arr[i] + maxProfitDP(arr, n, i + 1, true,dp), maxProfitDP(arr, n, i + 1, false,dp));

    return dp[i][canBuy] = profit;
}

int main() {
    int* arr = new int[6] {7, 1, 5, 3, 6, 4};
    vector<vector<int>> dp = vector(7,vector(2,-1));
    int n = 6;
    cout << endl << maxProfitDP(arr, n, 0, true,dp) << endl;
    return 0;
}