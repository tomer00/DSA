#include <iostream>
using namespace std;


int main() {
    int* arr, n;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter " << n << " space separated elements: ";
    for (int i = 0;i < n;i++) cin >> arr[i];

    int minN = __INT_MAX__, maxN = INT8_MIN, sum = 0;

    for (int i = 0;i < n;i++) {
        minN = min(minN, arr[i]);
        maxN = max(maxN, arr[i]);
        sum += arr[i];
    }

    cout << "Min : " << minN << "  Max : " << maxN << "  Sum of all : " << sum << endl;

    cout << "Reverse of above array : ";
    for (int i = n - 1;i > -1;i--) cout << arr[i] << " ";
    cout << endl;

    return 0;
}