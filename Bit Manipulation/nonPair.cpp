#include <iostream>
using namespace std;

int findNonPair(int *arr,int n){
    int ans = 0;
    for(int i=0;i<n;i++) ans^=arr[i];
    return ans;
}

int main(){
    int n, * arr;
    cout << "Enter Size of Array : ";
    cin >> n;
    arr = new int[n];
    cout << "Enter Space separated elements : ";
    for (int i = 0;i < n;i++)
        cin >> arr[i];
        
    cout<<"Only non Pair is : "<<findNonPair(arr,n)<<endl;
    return 0;
}