#include <iostream>
using namespace std;

int linearSearch(int ele, int* arr, int n) {
    for (int i = 0;i < n;i++)
        if (arr[i] == ele) return i;

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
        << linearSearch(ele, arr, n)
        << " index" << endl;
    return 0;
}