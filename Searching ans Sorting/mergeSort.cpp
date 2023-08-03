#include <iostream>
using namespace std;

void mergeSorted(int* arr, int s, int e) {
    int mid = s + ((e - s) >> 1);
    int* nArr = new int[e - s + 1];
    int i1 = s, i2 = mid + 1, i3 = 0;
    while (i1 <= mid && i2 <= e) {
        if (arr[i1] < arr[i2])
            nArr[i3++] = arr[i1++];
        else nArr[i3++] = arr[i2++];
    }
    while (i1 <= mid)
        nArr[i3++] = arr[i1++];
    while (i2 <= e)
        nArr[i3++] = arr[i2++];

    i1 = 0;i2 = s;
    while (i2 <= e)
        arr[i2++] = nArr[i1++];

    delete []nArr;
}

void mergeRec(int* arr, int s, int e) {
    if (s >= e) return;

    int mid = s + ((e - s) >> 1);
    mergeRec(arr, s, mid);
    mergeRec(arr, mid + 1, e);

    mergeSorted(arr, s, e);
}
void mergeSort(int* arr, int n) {
    mergeRec(arr, 0, n - 1);
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
    mergeSort(arr, n);
    printArr(arr, n);
    return 0;
}