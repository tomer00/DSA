#include <iostream>
using namespace std;


int main(){

    cout<<"Enter no to check for Odd Even : ";
    int n;
    cin>>n;

    if(n&1) cout<<n<<" is an Odd no..."<<endl;
    else cout<<n<<" is an Even no..."<<endl;

    return 0;
}