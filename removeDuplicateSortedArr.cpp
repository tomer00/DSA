#include <iostream>
using namespace std;

void printUnique(int* arr, int n) {
    if (n < 2) return;
    int l = 0, h = 1;
    cout << arr[0] << " ";
    while (h != n) {
        if (arr[h] != arr[l]) {
            l = h;
            cout << arr[l] << " ";
        }
        h++;
    }
    cout << endl;
}

int main() {

    cout << "Enter size of Array : ";
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated ascending elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    printUnique(arr, n);
    return 0;
}