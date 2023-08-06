#include <iostream>
using namespace std;

int findPivot(int* arr, int s, int e) {
    int pivot = arr[s];
    int i = s, j = e;
    while (i < j) {
        while (arr[i] <= pivot && i < e) i++;
        while (arr[j] > pivot && j > s) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j],arr[s]);
    return j;
}
void quickSort(int* arr, int s, int e) {
    if (s < e) {
        int pivot = findPivot(arr, s, e);
        quickSort(arr, s, pivot - 1);
        quickSort(arr, pivot + 1, e);
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
    quickSort(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}