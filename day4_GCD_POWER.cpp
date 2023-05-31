#include <iostream>
using namespace std;
const int M = 1e9 + 7;

// (a*b = lcm * gcd) //formula
//time O(log(n))
// gcd of 3 nos = gcd(gcd(a,b),c)
//Euclid GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
//from above formula
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// recursive relation = f(a,n) = f(a,b/2)*f(a,b/2)
//Fast Power a^n
int pow(int a, int n) {
    if (n == 0) return 1;

    int p = pow(a, n >> 1);
    //odd power
    if (n & 1) 
        return ((p * 1LL * p) % M * a) % M;
    //even power
    else return (p * 1LL * p) % M;
}

//Power by checking set bits
int powIterative(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        n >>= 1;
    }
    return ans;
}

int main() {

    int n1, n2;
    cout << "Enter two no's : ";
    cin >> n1 >> n2;

    cout << "GCD " << gcd(n1, n2) << endl;
    cout << "LCM " << lcm(n1, n2) << endl;
    cout << "POW " << pow(n1, n2) << endl;
    cout << "POWITE " << powIterative(n1, n2) << endl;

    return 0;
}