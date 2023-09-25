#include <iostream>
using namespace std;

//better Approach
bool isPrime(int no) {
    bool* arr = new bool[101];
    arr[0] = arr[1] = 1;
    for (int i = 2;i < 101;i++) {
        if (arr[i] == 1)continue;
        for (int j = i * i;j < 101;j +=i) {
            arr[j] = 1;
        }
    }
}

int main() {
    cout << "Enter no to check for Prime NO: ";
    int no;
    cin >> no;
    cout << no << (isPrime(no) ? " is a Prime..." : " is not a Prime...") << endl;
    return 0;
}