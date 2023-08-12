#include <iostream>
using namespace std;

void rotArray1(int* arr, int n, int rot) {
    rot = rot % n;
    int t;
    while (rot--) {
        t = arr[n - 1];
        for (int i = n-1;i > 0;i--)
            arr[i] = arr[i-1];
        arr[0] = t;
    }
}
void revArr(int* arr, int s, int e){
    while(s<e)
        swap(arr[s++],arr[e--]);
}
void rotArray2(int* arr, int n, int rot) {
    rot = rot % n;
    revArr(arr,0,n-1);
    revArr(arr,0,rot-1);
    revArr(arr,rot,n-1);
}
void printArr(int* arr, int n) {
    for (int i = 0;i < n;i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n, * arr, ele, rot;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cout << "Enter no of rotation : ";
    cin >> rot;
    rotArray2(arr, n, rot);
    printArr(arr, n);
    return 0;
}