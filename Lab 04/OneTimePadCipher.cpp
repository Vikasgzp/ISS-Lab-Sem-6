#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, string key) {
    string cipher = "";
    for (int i = 0; i < text.length(); i++)
        cipher += ((text[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
    return cipher;
}

string decrypt(string cipher, string key) {
    string text = "";
    for (int i = 0; i < cipher.length(); i++)
        text += ((cipher[i] - key[i] + 26) % 26) + 'A';
    return text;
}

int main() {
    string text = "CLASSCSE";
    string key = "XMCKL";

    string enc = encrypt(text, key);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << decrypt(enc, key);

    return 0;
}