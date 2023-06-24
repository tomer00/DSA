#include <iostream>
#include <map>
using namespace std;

void findUnique(int* arr, int n) {
    map<int, int> m;
    for (int i = 0;i < n;i++) {
        if (m[arr[i]] == 0) {
            m[arr[i]] = 1;
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {

    cout << "Enter size of Array : ";
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    cout << "Unique elements are : ";
    findUnique(arr, n);
    return 0;
}