#include <iostream>
using namespace std;

void print(string txt, int index) {
    if (txt.size() == index) {
        cout << txt << endl;
        return;
    }


    if (txt[index] == '?') {
        txt[index] = '0';
        print(txt, index + 1);


        txt[index] = '1';
        print(txt, index + 1);
    }
    else print(txt, index + 1);
}

int main() {

    string pat = "1??0?101";
    print(pat, 0);

    return 0;
}
