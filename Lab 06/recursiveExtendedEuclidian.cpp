#include <iostream>
using namespace std;

// Recursive function to find gcd and coefficients s, t
int extendedGCD(int a, int b, int &s, int &t) {
    // Base case
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }

    int s1, t1;

    // Recursive call
    int gcd = extendedGCD(b, a % b, s1, t1);

    // Update s and t (same relation as iterative shifting)
    s = t1;
    t = s1 - (a / b) * t1;

    return gcd;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int s, t;
    int gcd = extendedGCD(a, b, s, t);

    cout << "GCD = " << gcd << endl;
    cout << "s = " << s << ", t = " << t << endl;

    cout << "Verification: "
         << a << "*" << s << " + "
         << b << "*" << t << " = "
         << (a * s + b * t) << endl;

    return 0;
}