#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
    n--;
    bool isSwaped = false;
    for (int i = 0;i < n;i++) {
        isSwaped = false;
        for (int j = 0;j < n;j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwaped = true;
            }
        }
        if (!isSwaped) return;
    }
}

void printArr(int* arr, int n) {
    for (int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n, * arr;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    bubbleSort(arr, n);
    printArr(arr, n);
    return 0;
}