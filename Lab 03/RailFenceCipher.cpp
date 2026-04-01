#include <bits/stdc++.h>
using namespace std;

string encryptRailFence(string text, int key) {
    vector<string> rail(key);

    int dir = 1;
    int row = 0;

    for (int i = 0; i < text.length(); i++) {
        rail[row] += text[i];

        if (row == 0)
            dir = 1;
        else if (row == key - 1)
            dir = -1;

        row += dir;
    }

    string cipher = "";
    for (int i = 0; i < key; i++)
        cipher += rail[i];

    return cipher;
}

int main() {
    string text;
    int key;

    cout << "Enter plaintext: ";
    getline(cin,text);

    cout << "Enter number of rails: ";
    cin >> key;

    string cipher = encryptRailFence(text, key);

    cout << "Encrypted Text: " << cipher << endl;

    return 0;
}
