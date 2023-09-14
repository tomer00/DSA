#include <iostream>
#include <queue>
using namespace std;

int kThLarge(int* arr, int n, int k) {
    priority_queue<int> pq;

    for (int i = 0;i < k;i++)
        pq.push(arr[i]);
    
    for (int i = k;i < n;i++) {
        if (pq.top() > arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main() {

    cout << "Enter size of Array : ";
    int n, no, k;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " space separated elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];

    cout << "Enter value of k : ";
    cin >> k;
    if (k > n) cout << "K should be less than n.." << endl;

    cout << kThLarge(arr, n, k);

    return 0;
}