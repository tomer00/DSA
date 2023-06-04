#include <iostream>
#include <vector>
using namespace std;

//Recursive Solution without DP
int maxProfit(int* arr, int n, int i, bool canBuy) {

    if (i == n) return 0;
    int profit = 0;
    if (canBuy) {
        int purchased = -arr[i] + maxProfit(arr, n, i + 1, false);
        int skipped = maxProfit(arr, n, i + 1, true);
        profit = max(purchased, skipped);
    }else {
        int purchased = (arr[i] + maxProfit(arr, n, i + 1, true));
        int skipped = maxProfit(arr, n, i + 1, false);
        profit = max(purchased, skipped);
    }
    return profit;
}

//Solutoin with DP memoization
int maxProfitDP(int* arr, int n, int i, bool canBuy, vector<vector<int>>& dp) {

    if (i == n) return 0;
    if (dp[i][canBuy] != -1) return dp[i][canBuy];
    int profit = 0;
    if (canBuy) {
        int purchased = -arr[i] + maxProfitDP(arr, n, i + 1, false, dp);
        int skipped = maxProfitDP(arr, n, i + 1, true, dp);
        profit = max(purchased, skipped);
    }else {
        int purchased = (arr[i] + maxProfitDP(arr, n, i + 1, true, dp));
        int skipped = maxProfitDP(arr, n, i + 1, false, dp);
        profit = max(purchased, skipped);
    }

    return dp[i][canBuy] = profit;
}

int main() {
    int* arr = new int[12] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<vector<int>> dp = vector(12, vector(2, -1));
    int n = 12;
    cout << endl << maxProfitDP(arr, n, 0, true, dp) << endl;
    return 0;
}