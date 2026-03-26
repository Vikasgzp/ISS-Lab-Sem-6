#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file;
    file.open("input.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 0;
    }

    vector<int> freq(26, 0);
    char ch;

    while (file.get(ch)) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            freq[ch - 'a']++;
        }
    }

    file.close();

    cout << "Frequency Analysis:\n";
    cout << "-------------------\n";
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << " : " << freq[i] << endl;
    }

    return 0;
}
