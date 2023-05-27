#include <iostream>
#include <vector>
using namespace std;


int buyChoco(vector<int>& prices, int money) {
    int n = prices.size();
    int min = 1e9, ind;
    for (int i = 0;i < n;i++)
        if (prices[i] < min) {
            min = prices[i];
            ind = i;
        }

    int two = min;
    prices[ind] = min = 1e9;
    for (int i = 0;i < n;i++)
        if (prices[i] < min)
            min = prices[i];

    two += min;
    if (two > money) {
        return money;
    }
    else return money - two;
}


int main() {

    vector<int> pri(6);
    pri[0] = 61;
    pri[2] = 12;
    pri[3] = 87;
    pri[4] = 97;
    pri[5] = 17;
    pri[1] = 9;
    int money = 20;
    cout << buyChoco(pri, money) << endl;
    return 0;
}