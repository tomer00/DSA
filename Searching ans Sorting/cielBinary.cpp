#include <iostream>
using namespace std;

int cielOFNo(int* arr, int n, int ele) {
    int l = 0, h = n - 1;
    int m;
    while (l <= h) {
        m = l + (h - l) / 2;
        if (arr[m] == ele) {
            return m == n - 1 ? -1 : arr[m + 1];
        }
        else if (arr[m] > ele) h = m - 1;
        else l = m + 1;
    }
    if (arr[m] < ele) {
        return m == n - 1 ? -1 : arr[m + 1];
    }
    else {
        return m == 0 ? arr[0] : arr[m - 1];
    }
}

int main() {

    int n, * arr, ele;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cout << "Ceiling of  : ";
    cin >> ele;
    cout << "Ceiling of no : " << ele << " is : "
        << cielOFNo(arr, n, ele) << endl;
    return 0;
}