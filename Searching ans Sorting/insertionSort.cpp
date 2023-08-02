#include <iostream>
using namespace std;

void insertionSort1(int* arr, int n) {
    int j = 0;
    for (int i = 1;i < n;i++) {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}
void insertionSort2(int* arr, int n) {
    for (int i = 1;i < n;i++) {
        int temp = arr[i];
        int j = i - 1;
        for (;j > -1;j--) {
            if (arr[j] > temp) arr[j + 1] = arr[j];
            else break;
        }
        arr[j + 1] = temp;
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
    insertionSort2(arr, n);
    printArr(arr, n);
    return 0;
}