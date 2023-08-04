#include <iostream>
using namespace std;


void quickSort(int *arr,int n){
    
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
    quickSort(arr, n);
    printArr(arr, n);
    return 0;
}