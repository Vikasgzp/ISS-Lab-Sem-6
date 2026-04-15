#include <iostream>
using namespace std;

void extendedGCD(int a, int b) {
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;

    while (r2 != 0) {
        int q = r1 / r2;

        int r = r1 - q * r2;
        int s = s1 - q * s2;
        int t = t1 - q * t2;

        r1 = r2;
        r2 = r;

        s1 = s2;
        s2 = s;

        t1 = t2;
        t2 = t;
    }

    cout << "GCD = " << r1 << endl;
    cout << "s = " << s1 << ", t = " << t1 << endl;

    cout << "Output: "
         << a << "*" << s1 << " + "
         << b << "*" << t1 << " = "
         << (a * s1 + b * t1) << endl;
}



int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    extendedGCD(a, b);

    return 0;
}