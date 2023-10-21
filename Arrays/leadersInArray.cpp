#include <iostream>
#include <stack>
using namespace std;



void prefixSum(int* arr, int n, stack<int>& s) {
    s.push(arr[n - 1]);
    for (int i = n - 2;i > -1;i--)
        if (arr[i] > s.top()) s.push(arr[i]);
}

int main() {

    cout << "Enter size of Array : ";
    int n, no;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    stack<int> s;
    prefixSum(arr, n, s);

    cout << "Leader Elements : ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout<<endl;

    return 0;
}