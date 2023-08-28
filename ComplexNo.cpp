#include <iostream>

using namespace std;

class ComplexNumbers {
    bool signI = false;
public:
    int real, imag;
    ComplexNumbers(int r, int i) {
        real = r;
        imag = i;
    }
    void plus(ComplexNumbers c2) {
        real += c2.real;
        imag += c2.imag;
        signI = imag > -1;
    }
    void multiply(ComplexNumbers c2) {
        int r = real;
        real = (real * c2.real) - (imag * c2.imag);
        imag = (imag * c2.real) + (r * c2.imag);
        signI = imag > -1;
    }
    void print() {
        cout << real;
        if (signI) {
            cout << " + i" << imag;
        }        
else cout << " - i" << -imag;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
}