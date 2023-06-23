#include <iostream>
using namespace std;

int findMajority(int* arr, int n) {
    int ele = arr[0], count = 1;
    for (int i = 1;i < n;i++) {
        if (ele == arr[i]) count++;
        else count--;
        if (count == 0) {
            ele = arr[i];
            count = 1;
        }
    }
    return ele;
}

int main() {
    cout<<"Enter size of Array : ";
    int n;
    cin >> n;
    int* arr = new int[n];
    cout<<"Enter "<<n<<" space separated elements :";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    
    cout << "Majority element is : " << findMajority(arr,n) << endl;
    return 0;
}