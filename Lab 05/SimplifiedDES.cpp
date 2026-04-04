#include <bits/stdc++.h>
using namespace std;

// Permutation function
string permute(string input, int* perm, int n) {
    string output = "";
    for (int i = 0; i < n; i++)
        output += input[perm[i] - 1];
    return output;
}

// Left shift
string shift_left(string k, int shifts) {
    string s = "";
    for (int i = 0; i < shifts; i++) {
        for (int j = 1; j < k.size(); j++)
            s += k[j];
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}

// XOR
string XOR(string a, string b) {
    string res = "";
    for (int i = 0; i < a.size(); i++)
        res += (a[i] == b[i]) ? '0' : '1';
    return res;
}

// S-Boxes
int S0[4][4] = {
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4] = {
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

// Function F
string F(string right, string key) {
    int EP[8] = {4,1,2,3,2,3,4,1};
    string expanded = permute(right, EP, 8);

    string x = XOR(expanded, key);

    string left = x.substr(0,4);
    string right_part = x.substr(4,4);

    // S0
    int row = (left[0]-'0')*2 + (left[3]-'0');
    int col = (left[1]-'0')*2 + (left[2]-'0');
    int val = S0[row][col];
    string s0 = bitset<2>(val).to_string();

    // S1
    row = (right_part[0]-'0')*2 + (right_part[3]-'0');
    col = (right_part[1]-'0')*2 + (right_part[2]-'0');
    val = S1[row][col];
    string s1 = bitset<2>(val).to_string();

    string combined = s0 + s1;

    int P4[4] = {2,4,3,1};
    return permute(combined, P4, 4);
}

// Key Generation
void generate_keys(string key, string &K1, string &K2) {
    int P10[10] = {3,5,2,7,4,10,1,9,8,6};
    int P8[8]  = {6,3,7,4,8,5,10,9};

    key = permute(key, P10, 10);

    string left = key.substr(0,5);
    string right = key.substr(5,5);

    left = shift_left(left,1);
    right = shift_left(right,1);

    K1 = permute(left + right, P8, 8);

    left = shift_left(left,2);
    right = shift_left(right,2);

    K2 = permute(left + right, P8, 8);
}

// Encryption
string encrypt(string pt, string K1, string K2) {
    int IP[8] = {2,6,3,1,4,8,5,7};
    int IP_inv[8] = {4,1,3,5,7,2,8,6};

    pt = permute(pt, IP, 8);

    string left = pt.substr(0,4);
    string right = pt.substr(4,4);

    // Round 1
    string temp = XOR(left, F(right, K1));
    string swapped = right + temp;

    // Round 2
    left = swapped.substr(0,4);
    right = swapped.substr(4,4);

    temp = XOR(left, F(right, K2));

    string combined = temp + right;

    return permute(combined, IP_inv, 8);
}

// Decryption
string decrypt(string ct, string K1, string K2) {
    // Same as encryption but keys reversed
    return encrypt(ct, K2, K1);
}

int main() {
    string key = "1010000010";   // 10-bit key
    string pt  = "11010111";     // 8-bit plaintext

    string K1, K2;
    generate_keys(key, K1, K2);

    cout << "K1: " << K1 << endl;
    cout << "K2: " << K2 << endl;

    string ct = encrypt(pt, K1, K2);
    cout << "Encrypted: " << ct << endl;

    cout << "Decrypted: " << decrypt(ct, K1, K2) << endl;

    return 0;
}