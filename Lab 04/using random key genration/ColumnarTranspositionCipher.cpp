#include <bits/stdc++.h>
using namespace std;

string generateKey(int len) {
    string key = "";
    for (int i = 0; i < len; i++)
        key += 'A' + rand() % 26;
    return key;
}

string encrypt(string text, string key) {
    int col = key.length();
    int row = ceil((float)text.length() / col);

    vector<vector<char>> grid(row, vector<char>(col, '_'));

    int k = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (k < text.length()) grid[i][j] = text[k++];

    vector<pair<char, int>> keyMap;
    for (int i = 0; i < col; i++)
        keyMap.push_back({key[i], i});

    sort(keyMap.begin(), keyMap.end());

    string cipher = "";
    for (auto it : keyMap)
        for (int i = 0; i < row; i++)
            cipher += grid[i][it.second];

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
    for (auto it : keyMap)
        for (int i = 0; i < row; i++)
            if (k < cipher.length())
                grid[i][it.second] = cipher[k++];

    string text = "";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (grid[i][j] != '_')
                text += grid[i][j];

    return text;
}

int main() {
    srand(time(0));

    string text;
    cout << "Enter plaintext: ";
    cin >> text;

    string key = generateKey(5);

    string enc = encrypt(text, key);

    cout << "Generated Key: " << key << endl;
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << decrypt(enc, key);

    return 0;
}