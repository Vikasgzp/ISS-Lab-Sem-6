#include <iostream>
using namespace std;

int phi(int n) {
    int result = n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    // If n is still > 1, it is prime
    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Euler Totient φ(n) = " << phi(n) << endl;

    return 0;
}