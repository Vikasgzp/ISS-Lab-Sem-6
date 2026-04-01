#include <bits/stdc++.h>
using namespace std;

string generateKey(string text, string key) {
    int x = text.length();

    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (key.length() == text.length())
            break;
        key += key[i];
    }
    return key;
}

string decryptVigenere(string cipher, string key) {
    string text = "";

    for (int i = 0; i < cipher.length(); i++) {
        int x = (cipher[i] - key[i] + 26) % 26;
        x += 'A';
        text += char(x);
    }

    return text;
}

int main() {
    string cipher, key;

    cout << "Enter cipher text (uppercase): ";
    cin >> cipher;

    cout << "Enter key (uppercase): ";
    cin >> key;

    key = generateKey(cipher, key);

    string text = decryptVigenere(cipher, key);

    cout << "Decrypted Text: " << text << endl;

    return 0;
}
