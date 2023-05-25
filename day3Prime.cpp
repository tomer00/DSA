#include <iostream>
#include <vector>
using namespace std;

// this is a simple function to check if n is prime
// O(n) is time complexity
bool checkPrime(int n) {
    if (n <= 1) return false;
    int n1 = n >> 1;
    for (int i = 2;i <= n1;i++) if (n % i == 0) return false;
    return true;
}

// count or print all prime within the range
// Sieve of Eratosthenes
// time used is O(n*(log(logn)))
int countPrime(int n) {
    // n+1 to make indexing easy
    // initialize all places with true first
    vector<bool> v(n + 1, true);

    int coun = 0;
    v[0] = v[1] = false;

    for (int i = 2;i <= n;i++)
        if (v[i]) {
            coun++;
            // starting with twice of i
            // marking its multiple non primes
            for (int j = (i << 1);j <= n;j += i)
                v[j] = false;
        }
    
    return coun;
}

int main() {
    int c = 0;
    // this approach is using O(n2) time
    for (int i = 0;i < 20;i++) {
        if (checkPrime(i)) {
            c++;
        }
    }

    cout << c << "  " << countPrime(19) << endl;
    return 0;
}