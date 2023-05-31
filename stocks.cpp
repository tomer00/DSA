#include <iostream>
using namespace std;

int maxProfit(int* arr, int n) {
    int ans = -1, minN = arr[0];
    for (int i = 1;i < n;i++) {
        ans = max(ans, arr[i] - minN);
        minN = min(minN, arr[i]);
    }
    return ans;
}

int main() {


    int* arr = new int[6] {7, 6, 5, 4, 3, 2};
    int n = 6;
    for (int i = 0;i < n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl << maxProfit(arr, n) << endl;
    return 0;
}