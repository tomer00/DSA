#include <iostream>
#include <vector>
using namespace std;

int minCoins(int* coins, int no, int n) {
    if (no == 0) return 0;
    if (no < 0) return __INT_MAX__;

    int mini = __INT_MAX__;
    for (int i = 0;i < n;i++) {
        int ans = minCoins(coins, no - coins[i], n);
        if (ans != __INT_MAX__)
            mini = min(mini, 1 + ans);
    }
    return mini;
}

int minCoins(int* coins, int no, int n, vector<int>& dp) {
    if (no == 0) return 0;
    if (no < 0) return __INT_MAX__;

    if (dp[no] != -1) return dp[no];


    int mini = __INT_MAX__;
    for (int i = 0;i < n;i++) {
        int ans = minCoins(coins, no - coins[i], n, dp);
        if (ans != __INT_MAX__)
            mini = min(mini, 1 + ans);
    }
    return dp[no] = mini;
}

int minCoinsTAB(int* coins, int no, int n) {
    vector<int> dp(no + 1, __INT_MAX__);
    dp[0] = 0;
    for (int i = 1;i <= no;i++)
        for (int j = 0; j < n; j++) {
            if (i - coins[j] > -1)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    return dp[no];
}

int main() {

    int* coins = new int[5] {1,3,9,12,14};
    int no;
    cout << "Enter Sum you want to make : ";
    cin >> no;

    // vector<int> dp(no + 1, -1);
    cout << "Minimum coins to make sum of " << no << " : " << minCoinsTAB(coins, no, 5) << endl;
    return 0;
}