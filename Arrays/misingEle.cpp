#include <iostream>
using namespace std;



//Save occurance in map
//costing O(n) space not optimized

//Sort arr and find missing

//Sum from 1 to n and then subtract from this
int missingEle(int* arr, int n) {
    int sum = n * (n + 1);
    sum >>= 1;
    for (int i = 0;i < n;i++)
        sum -= arr[i];
    return sum;
}

int main() {

    cout << "Enter value of n : ";
    int n, no;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter space separated elements " << n - 1 << " elements : ";
    n--;
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    n++;
    cout << "Missing element form arr is : " << missingEle(arr, n) << endl;
    return 0;
}