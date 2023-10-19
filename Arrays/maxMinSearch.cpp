#include <iostream>
using namespace std;

pair<int, int> minMax(int* arr, int n) {
    int min = 0;
    int max = min = arr[0];

    for(int i=1;i<n;i++){
       if(arr[i]<min) min = arr[i];
       if(arr[i]>max) max = arr[i];
    }

    return make_pair(max,min);
}

int main() {

    cout << "Enter size of Array : ";
    int n, no;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    pair<int, int> p = minMax(arr, n);
    cout << "Max element in arr : " << p.first << endl;
    cout << "Min element in arr : " << p.second << endl;
    return 0;
}