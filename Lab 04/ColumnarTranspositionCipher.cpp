#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, string key) {
    int col = key.length();
    int row = ceil((float)text.length() / col);

    vector<vector<char>> grid(row, vector<char>(col, '_'));

    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (k < text.length())
                grid[i][j] = text[k++];
        }
    }

    vector<pair<char, int>> keyMap;
    for (int i = 0; i < col; i++)
        keyMap.push_back({key[i], i});

    sort(keyMap.begin(), keyMap.end());

    string cipher = "";
    for (auto it : keyMap) {
        int j = it.second;
        for (int i = 0; i < row; i++)
            cipher += grid[i][j];
    }

    return cipher;
}

string decrypt(string cipher, string key) {
    int col = key.length();
    int row = ceil((float)cipher.length() / col);

    vector<vector<char>> grid(row, vector<char>(col));

    vector<pair<char, int>> keyMap;
    for (int i = 0; i < col; i++)
        keyMap.push_back({key[i], i});

    sort(keyMap.begin(), keyMap.end());

    int k = 0;
    for (auto it : keyMap) {
        int j = it.second;
        for (int i = 0; i < row; i++) {
            if (k < cipher.length())
                grid[i][j] = cipher[k++];
        }
    }

    string text = "";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] != '_')
                text += grid[i][j];
        }
    }

    return text;
}

int main() {
    string text = "JINDABAD";
    string key = "KEY";

    string enc = encrypt(text, key);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << decrypt(enc, key);

    return 0;
}