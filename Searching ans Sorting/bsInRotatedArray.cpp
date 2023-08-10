#include <iostream>
using namespace std;


//for unique elements
int bsRotated(int ele, int* arr, int n) {
    int l = 0, h = n - 1;
    int m;
    while (l <= h) {
        m = l + (h - l) / 2;
        if (arr[m] == ele) return m;
        //check the sorted hafl
        if (arr[l] <= arr[m]) {
            if (arr[l] <= ele && ele <= arr[m]) h = m - 1;
            else l = m + 1;
        }
        else {
            if (arr[m] <= ele && ele <= arr[h]) l = m + 1;
            else h = m + 1;
        }

    }

    return -1;
}
void rotF(int* arr, int n, int rot) {
    rot = rot % n;
    int t;
    while (rot--) {
        t = arr[n - 1];
        for (int i = n-1;i > 0;i--)
            arr[i] = arr[i-1];
        arr[0] = t;
    }
}
void printArr(int* arr, int n) {
    for (int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n, * arr, ele, rot;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cout << "Enter no of rotation : ";
    cin >> rot;
    rotF(arr, n, rot);
    printArr(arr, n);
    cout << "Element to find : ";
    cin >> ele;
    cout << "Element is present at "
        << bsRotated(ele, arr, n)
        << " index" << endl;
    return 0;
}