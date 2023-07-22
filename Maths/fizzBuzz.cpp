#include <iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter no to Print Fizz Buzz upto: ";
    cin>>n;
    bool any;
    for(int i=1;i<=n;i++){
        any = false;
        if(i%3==0){
            any=true;
            cout<<"Fizz";
        }
        if(i%5==0){
            any=true;
            cout<<"Buzz";
        }
        if(!any) cout<<i;
        cout<<endl;
    }
    return 0;
}