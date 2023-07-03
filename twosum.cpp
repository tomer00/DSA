#include <iostream>
using namespace std;

pair<int, int> findPair(int* arr, int n, int target) {
    int h = n - 1;
    int l = 0;
    while (l < h) {
        int t=arr[l]+arr[h];
        if(t==target) return make_pair(arr[l],arr[h]);
        if(t<target) l++;
        else h--;
    }
    return make_pair(-1,-1);
}
int main() {

    cout << "Enter size of Array : ";
    int n;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated ascending elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    int target;
    cout << "Enter taget sum to be made : ";
    cin >> target;

    pair<int, int> ans = findPair(arr, n, target);
    cout << "Two elements for sum are : " << ans.first << "  " << ans.second << endl;
    return 0;
}