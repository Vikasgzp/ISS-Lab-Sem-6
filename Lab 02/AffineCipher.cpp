#include <bits/stdc++.h>
using namespace std;

// Function to find modular inverse of a under mod 26
int modInverse(int a) {
    for (int i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main() {
    string text;
    int a, b;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key a (coprime with 26): ";
    cin >> a;

    cout << "Enter key b: ";
    cin >> b;

    int a_inv = modInverse(a);
    if (a_inv == -1) {
        cout << "Invalid key! 'a' has no modular inverse." << endl;
        return 0;
    }

    string encrypted = "", decrypted = "";

    // ---------- Encryption ----------
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int p = ch - base;

            encrypted += (a * p + b) % 26 + base;
        } else {
            encrypted += ch;
        }
    }

    cout << "Encrypted Text: " << encrypted << endl;

    // ---------- Decryption ----------
    for (char ch : encrypted) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int c = ch - base;

            decrypted += (a_inv * (c - b + 26)) % 26 + base;
        } else {
            decrypted += ch;
        }
    }

    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
