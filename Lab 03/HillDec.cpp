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

void inverseKeyMatrix(int keyMatrix[2][2], int invMatrix[2][2]) {
    int det = keyMatrix[0][0]*keyMatrix[1][1] -
              keyMatrix[0][1]*keyMatrix[1][0];

    det = (det % 26 + 26) % 26;

    int invDet = modInverse(det);

    invMatrix[0][0] = keyMatrix[1][1];
    invMatrix[1][1] = keyMatrix[0][0];
    invMatrix[0][1] = -keyMatrix[0][1];
    invMatrix[1][0] = -keyMatrix[1][0];

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            invMatrix[i][j] = (invMatrix[i][j] % 26 + 26) % 26;

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            invMatrix[i][j] = (invMatrix[i][j] * invDet) % 26;
}

string decryptHill(string cipher, int invMatrix[2][2]) {
    string text = "";

    for(int i=0;i<cipher.length();i+=2) {
        int x = cipher[i] - 'A';
        int y = cipher[i+1] - 'A';

        int p1 = (invMatrix[0][0]*x + invMatrix[0][1]*y) % 26;
        int p2 = (invMatrix[1][0]*x + invMatrix[1][1]*y) % 26;

        text += char(p1 + 'A');
        text += char(p2 + 'A');
    }

    return text;
}

int main() {
    string cipher, key;

    cout << "Enter cipher text (uppercase): ";
    cin >> cipher;

    cout << "Enter 4-letter key (uppercase): ";
    cin >> key;

    int keyMatrix[2][2], invMatrix[2][2];

    getKeyMatrix(key, keyMatrix);
    inverseKeyMatrix(keyMatrix, invMatrix);

    string text = decryptHill(cipher, invMatrix);

    cout << "Decrypted Text: " << text << endl;

    return 0;
}
