#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool contains(vector<int>& v, int n) {
    for (auto i : v) if (i == n) return true;
    return false;
}

//O(n*m)
vector<int> printUnion1(int* arr1, int n, int* arr2, int m) {

    vector<int> v;
    for (int i = 0;i < n;i++)
        if (!contains(v, arr1[i])) v.push_back(arr1[i]);
    for (int i = 0;i < m;i++)
        if (!contains(v, arr2[i])) v.push_back(arr2[i]);

    return v;
}
//o(n)
vector<int> printUnion2(int* arr1, int n, int* arr2, int m) {

    unordered_map<int, bool> map;
    int i = 0, j = 0;
    for (int i = 0;i < n;i++) {
        if (map[arr1[i]]) map[arr1[i]] = true;
    }
    for (int i = 0;i < m;i++) {
        if (map[arr2[i]]) map[arr2[i]] = true;
    }
    vector<int> v;
    for(auto i :map) v.push_back(i.first);
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


    for (auto i : printUnion1(arr1, n, arr2, m)) cout << i << " ";
    cout << endl;

    return 0;
}