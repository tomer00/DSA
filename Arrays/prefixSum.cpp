#include <iostream>
using namespace std;



void prefixSum(int* arr, int n) {
    for (int i = 1;i < n;i++)
        arr[i] = arr[i - 1]+arr[i];
}

int main() {

    cout << "Enter size of Array : ";
    int n, no;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    prefixSum(arr,n);

    cout << "Prefix Sum : ";
    for (int i = 0;i < n;i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}