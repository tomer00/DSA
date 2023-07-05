#include <iostream>
using namespace std;

int* mergedArr(int* arr1, int* arr2, int n1, int n2) {
    int* ret = new int[n1 + n2];
    int i1 = 0, i2 = 0,i3=0;
    while (i1 < n1 && i2 < n2) {
        if(arr1[i1]<arr2[i2])
            ret[i3++] = arr1[i1++];
        else
            ret[i3++] = arr2[i2++];
    }

    while (i1 < n1) 
            ret[i3++] = arr1[i1++];
    while (i2 < n2) 
            ret[i3++] = arr2[i2++];
     return ret;
}

int main() {

    cout << "Enter size of List 1 and 2 : ";
    int n1, n2;
    cin >> n1 >> n2;
    int* arr1 = new int[n1];
    int* arr2 = new int[n2];
    cout << "Enter " << n1 << " ascending elements of l1 :";
    for (int i = 0;i < n1;i++)
        cin >> arr1[i];

    cout << "Enter " << n2 << " ascending elements of l2 :";
    for (int i = 0;i < n2;i++)
        cin >> arr2[i];

    int* merged = mergedArr(arr1, arr2, n1, n2);
    n1 += n2;

    for (int i = 0;i < n1;i++)
        cout << merged[i] << " ";

    cout << endl;

    return 0;
}