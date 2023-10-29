#include <iostream>
#include <vector>
using namespace std;

//using nested loops


//using hashing space O(n)
pair<int, int> missingAndRepeatingHash(int* arr, int n) {
    vector<int> v(n, 0);
    for (int i = 0;i < n;i++)
        v[arr[i] - 1]++;

    pair<int, int> ans = make_pair(0, 0);
    for (int i = 0;i < n;i++) {
        if (v[i] == 0) ans.first = i + 1;
        else if (v[i] == 2) ans.second = i + 1;
    }
    return ans;
}


//using Maths space O(1)
/*
    first find x-y
    find x^2 - y^2 split it in (x+y)(x-y)
    put upper x-y in here and find x+y
*/
pair<int, int> missingAndRepeatingMaths(int* arr, int n) {
    pair<int, int> ans = make_pair(0, 0);

    int sum = 0;
    int sumSq = 0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
        sumSq += arr[i] * arr[i];
    }

    int sn = n * (n + 1);
    sn >>= 1;
    int s2n = (n) * (n + 1) * ((n << 1) + 1);
    s2n /= 6;

    // this is x-y
    int eq1 = sum - sn;
    // this is x^2 - y^2
    int eq2 = sumSq - s2n;

    //this is x+y
    int eq3 = eq2 / eq1;

    ans.second = (eq1 + eq3) >> 1;
    ans.first = ans.second - eq1;

    return ans;
}


//using XOR space O(1)
pair<int, int> missingAndRepeatingXOR(int* arr, int n) {
    pair<int, int> ans = make_pair(0, 0);

    int xr = 0;
    for (int i = 0;i < n;i++) {
        xr ^= arr[i];
        xr ^= i + 1;
    }

    int rsb = xr & -xr;

    int x = 0, y = 0;

    for (int i = 0;i < n;i++) {
        if (arr[i] & rsb == 0) x ^= arr[i];
        else y ^= arr[i];
    }
    for (int i = 1;i <= n;i++) {
        if (i & rsb == 0) x ^= i;
        else y ^= i;
    }

    for (int i = 0;i < n;i++) {
        if (arr[i] == x) {
            ans.second = x;
            ans.first = y;
            break;
        }
        else if (arr[i] == y) {
            ans.first = x;
            ans.second = y;
            break;
        }
    }

    return ans;
}

int main() {

    cout << "Enter value of n : ";
    int n, no;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter space separated elements " << n << " elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    pair<int, int> ans = missingAndRepeatingXOR(arr, n);
    cout << "Missing element form arr is : " << ans.first << endl;
    cout << "Repeating element form arr is : " << ans.second << endl;
    return 0;
}