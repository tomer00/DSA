#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool contains(vector<int>& v, int n) {
    for (auto i : v) if (i == n) return true;
    return false;
}

//O(n^2)
vector<int> printInter1(int* arr1, int n, int* arr2, int m) {

    vector<int> v;
    for (int i = 0;i < n;i++) {
        if (contains(v, arr1[i])) continue;
        for (int j = 0;j < m;j++) {
            if (arr1[i] == arr2[j]) {
                v.push_back(arr1[i]);
                break;
            }
        }
    }
    return v;
}
vector<int> printInter2(int* arr1, int n, int* arr2, int m) {

    sort(&arr1[0], &arr1[n - 1]);
    sort(&arr2[0], &arr2[m - 1]);
    vector<int> v;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if(arr1[i]==arr2[j]){
            if(!contains(v,arr1[i])) v.push_back(arr1[i]);
            i++;j++;
        }else if(arr1[i]<arr2[j]) i++;
        else j++;
    }
    return v;
}



int main() {

    int n, * arr1, * arr2, m;
    cout << "Enter Size of Array1 : ";
    cin >> n;
    arr1 = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr1[i];

    cout << "Enter Size of Array2 : ";
    cin >> m;
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < m;i++)
        cin >> arr2[i];


    for (auto i : printInter2(arr1, n, arr2, m)) cout << i << " ";
    cout << endl;

    return 0;
}