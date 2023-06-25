#include <iostream>
using namespace std;


//iterative binary search
int binarySea(int* arr, int n, int ele) {
    if (n == 0) return -1;
    int h = n - 1, l = 0, mid;
    while (l <= h) {
        mid = l + (h - l) / 2;
        if (arr[mid] == ele) return mid;
        else if (arr[mid] < ele) l = mid + 1;
        else h = mid - 1;
    }
    return -1;
}

int main() {

    cout << "Enter size of Array : ";
    int n, no;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    cout << "Enter element to search : ";
    cin >> no;
    int in = binarySea(arr, n, no);
    if (in == -1) cout << "Element " << no << " not found in array" << endl;
    else cout << "Element " << no << " present at " << in << " index" << endl;
    return 0;
}