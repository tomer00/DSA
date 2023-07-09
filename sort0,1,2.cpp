#include <iostream>
using namespace std;

void sort(int* arr, int n) {
    int h = n - 1, l = 0, mid = 1;
    while (mid < h) {
        if (arr[mid] == 0) {
            arr[mid++] = arr[l];
            arr[l++] = 0;
        }
        else if (arr[mid] == 2) {
            arr[mid] = arr[h];
            arr[h--] = 2;
        }else mid++;
    }
}

int main() {
    cout << "Enter size of Array : ";
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " only 0 1 2 :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    
    sort(arr,n);
    cout << "Sored elements are : ";
    for (int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}