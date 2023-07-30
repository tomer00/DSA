#include <iostream>
using namespace std;

int floorOFNo(int* arr, int n, int ele) {
    int l = 0, h = n - 1;
    int m;
    while (l <= h) {
        m = l + (h - l) / 2;
        if (arr[m] == ele) {
            return arr[m];
        }
        else if (arr[m] > ele) h = m - 1;
        else l = m + 1;
    }
    if (arr[m] < ele)
        return arr[m];
    else return m == 0 ? -1 : arr[m - 1];
}

int main() {

    int n, * arr, ele;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cout << "Floor of  : ";
    cin >> ele;
    cout << "Floor of no : " << ele << " is : "
        << floorOFNo(arr, n, ele) << endl;
    return 0;
}