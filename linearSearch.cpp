#include <iostream>
using namespace std;


//Linear search function provides index
int linearSearch(int arr[], int n, int no) {
    for (int i = 0;i < n;i++) if (arr[i] == no) return i;
    return -1;
}

int main() {

    int* arr, n;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter " << n << " space separated elements: ";

    for (int i = 0;i < n;i++) cin >> arr[i];

    int no;
    cout << "Enter the no to find: ";
    cin >> no;

    cout << "No " << no << " found at index : " << linearSearch(arr, n, no) << endl;

    return 0;
}