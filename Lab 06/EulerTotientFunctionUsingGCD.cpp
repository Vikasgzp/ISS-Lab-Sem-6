#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int phi(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1)
            count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Euler Totient = " << phi(n) << endl;

    return 0;
}