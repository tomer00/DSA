#include <iostream>
using namespace std;

//passing pointers
//swapping with XOR operator
void swapXOR(int* n1, int* n2) {
    *n1 = *n1 ^ *n2;
    *n2 = *n1 ^ *n2;
    *n1 = *n1 ^ *n2;
}

//swaping with a third temp var
void swapTemp(int& n1, int& n2) {
    int t = n1;
    n1 = n2;
    n2 = t;
}

//swaping without a third temp var
void swapAdd(int& n1, int& n2) {
    n1 = n1 + n2;
    n2 = n1 - n2;
    n1 = n1 - n2;
}

//swaping with generics
template<class t>
void swapT(t& n1, t& n2) {
    t temp = n1;
    n1 = n2;
    n2 = temp;
}

int main() {
    string n1, n2;

    cout << "Enter 2 integer no to swap : ";
    cin >> n1;
    cin >> n2;

    cout << "Before swap n1 : " << n1 << " n2 : " << n2 << endl;
    swapT(n1, n2);
    cout << "After swap  n1 : " << n1 << " n2 : " << n2 << endl;

    return 0;
}