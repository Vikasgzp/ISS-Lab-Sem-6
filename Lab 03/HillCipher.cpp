#include <bits/stdc++.h>
using namespace std;

int modInverse(int a) {
    a = a % 26;
    for (int x = 1; x < 26; x++)
        if ((a * x) % 26 == 1)
            return x;
    return -1;
}

void getKeyMatrix(string key, int keyMatrix[2][2]) {
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            keyMatrix[i][j] = key[k++] - 'A';
}

string encryptHill(string text, int keyMatrix[2][2]) {
    string cipher = "";

    for (int i = 0; i < text.length(); i += 2) {
        int x = text[i] - 'A';
        int y = text[i+1] - 'A';

        int c1 = (keyMatrix[0][0]*x + keyMatrix[0][1]*y) % 26;
        int c2 = (keyMatrix[1][0]*x + keyMatrix[1][1]*y) % 26;

        cipher += char(c1 + 'A');
        cipher += char(c2 + 'A');
    }

    return cipher;
}

int main() {
    string text, key;

    cout << "Enter plaintext (uppercase, even length): ";
    cin >> text;

    cout << "Enter 4-letter key (uppercase): ";
    cin >> key;

    int keyMatrix[2][2];
    getKeyMatrix(key, keyMatrix);

    string cipher = encryptHill(text, keyMatrix);

    cout << "Encrypted Text: " << cipher << endl;

    return 0;
}
