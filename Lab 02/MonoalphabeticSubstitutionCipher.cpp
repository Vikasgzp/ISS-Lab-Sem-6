#include <bits/stdc++.h>
using namespace std;

int main() {
    string plaintext;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);

    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string cipher = "";

    // ---------- Encryption ----------
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char upper = toupper(ch);
            int index = upper - 'A';
            char enc = key[index];

            if (islower(ch))
                enc = tolower(enc);

            cipher += enc;
        } else {
            cipher += ch;
        }
    }

    cout << "Encrypted Text: " << cipher << endl;

    // ---------- Decryption ----------
    string decrypted = "";

    for (char ch : cipher) {
        if (isalpha(ch)) {
            char upper = toupper(ch);
            int index = key.find(upper);
            char dec = 'A' + index;

            if (islower(ch))
                dec = tolower(dec);

            decrypted += dec;
        } else {
            decrypted += ch;
        }
    }

    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
