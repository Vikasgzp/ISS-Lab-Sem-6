#include <bits/stdc++.h>
using namespace std;

string decryptRailFence(string cipher, int key) {
    vector<vector<char>> rail(key, vector<char>(cipher.length(), '\n'));

    bool dir_down;
    int row = 0, col = 0;

    // Mark zigzag positions
    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0) dir_down = true;
        if (row == key - 1) dir_down = false;

        rail[row][col++] = '*';

        row += dir_down ? 1 : -1;
    }

    // Fill marked positions with cipher letters
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    // Read in zigzag
    string result;
    row = 0; col = 0;

    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0) dir_down = true;
        if (row == key - 1) dir_down = false;

        result += rail[row][col++];

        row += dir_down ? 1 : -1;
    }

    return result;
}

int main() {
    string cipher;
    int key;

    cout << "Enter cipher text: ";
    getline(cin,cipher);

    cout << "Enter number of rails: ";
    cin >> key;

    string text = decryptRailFence(cipher, key);

    cout << "Decrypted Text: " << text << endl;

    return 0;
}
