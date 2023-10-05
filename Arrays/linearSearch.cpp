#include <iostream>
using namespace std;

int linearSearch(int* arr, int n, int ele) {
    for (int i = 0;i < n;i++) if (arr[i] == ele) return i;
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
    int in = linearSearch(arr, n, no);
    if (in == -1) cout << "Element " << no << " not found in array" << endl;
    else cout << "Element " << no << " present at " << in << " index" << endl;
    return 0;
}