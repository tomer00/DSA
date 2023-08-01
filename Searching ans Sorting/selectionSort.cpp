#include <iostream>
using namespace std;

void selectionSort(int* arr, int n) {
    int minIndex = -1;
    for (int i = 0;i < n - 1;i++) {
        minIndex = i;
        for (int j = i + 1;j < n;j++)
            if (arr[j] < arr[minIndex]) minIndex = j;
        swap(arr[i], arr[minIndex]);
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
    selectionSort(arr, n);
    printArr(arr, n);
    return 0;
}