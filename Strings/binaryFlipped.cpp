#include <iostream>
using namespace std;

bool binaryFlipped(string str) {
    int ones = 0, zeros = 0;
    for (auto c : str) {
        if (c == '1') ++ones;
        else if (c == '0') ++zeros;
    }
    int u = ones - zeros;
    if(u==-1||u==1) return true;
    return false;
}

int main()
{
    binaryFlipped("101") ? printf("Yes") : printf("No");
    return 0;
}
