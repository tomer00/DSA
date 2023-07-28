#include <iostream>
using namespace std;

int binarySearch(int ele, int* arr, int n) {
    int l = 0, h = n - 1;
    int m;
    while (l <= h) {
        m = l + (h - l) / 2;
        if (arr[m] == ele) return m;
        else if (arr[m] > ele) h = m - 1;
        else l = m + 1;
    }

    return -1;
}

int main() {
    int n, * arr, ele;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cout << "Element to find : ";
    cin >> ele;
    cout << "Element is present at "
        << binarySearch(ele, arr, n)
        << " index" << endl;
    return 0;
}