#include <iostream>
using namespace std;

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Modular inverse (simple brute-force)
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((d * e) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    int p, q;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e;

    // Take e from user and validate
    while (true) {
        cout << "Enter value of e (1 < e < " << phi << " and gcd(e, " << phi << ") = 1): ";
        cin >> e;

        if (e > 1 && e < phi && gcd(e, phi) == 1) {
            break;
        } else {
            cout << "Invalid e! Try again.\n";
        }
    }

    int d = modInverse(e, phi);

    int message;
    cout << "Enter message (integer): ";
    cin >> message;

    cout << "\nPublic Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;

    // Encryption
    int cipher = modExp(message, e, n);
    cout << "Encrypted Message: " << cipher << endl;

    // Decryption
    int decrypted = modExp(cipher, d, n);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}