#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, key;
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key: ";
    cin >> key;

    // normalize key
    for (char &c : key)
        c = tolower(c);

    string encrypted = "", decrypted = "";
    int keyIndex = 0;

    // ---------- Encryption ----------
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int p = ch - base;
            int k = key[keyIndex % key.length()] - 'a';

            encrypted += (p + k) % 26 + base;
            keyIndex++;
        } else {
            encrypted += ch;
        }
    }

    cout << "Encrypted Text: " << encrypted << endl;

    // ---------- Decryption ----------
    keyIndex = 0;
    for (char ch : encrypted) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int c = ch - base;
            int k = key[keyIndex % key.length()] - 'a';

            decrypted += (c - k + 26) % 26 + base;
            keyIndex++;
        } else {
            decrypted += ch;
        }
    }

    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
