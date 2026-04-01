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

string encryptVigenere(string text, string key) {
    string cipher = "";

    for (int i = 0; i < text.length(); i++) {
        int x = (text[i] + key[i]) % 26;
        x += 'A';
        cipher += char(x);
    }

    return cipher;
}

int main() {
    string text, key;

    cout << "Enter plaintext (uppercase): ";
    cin >> text;

    cout << "Enter key (uppercase): ";
    cin >> key;

    key = generateKey(text, key);

    string cipher = encryptVigenere(text, key);

    cout << "Encrypted Text: " << cipher << endl;

    return 0;
}
