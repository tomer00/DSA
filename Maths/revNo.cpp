#include <iostream>
using namespace std;

int revNo(int no) {
    int ans = 0;
    int rem = 1;
    while (no) {
        rem = no % 10;
        ans = ans * 10 + rem;
        no /= 10;
    }
    return ans;
}
int main() {
    cout << "Enter a no to reverse : ";
    int no;
    cin >> no;
    cout << "Reversed no : " << revNo(no) << endl;
    return 0;
}