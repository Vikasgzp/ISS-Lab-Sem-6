#include <bits/stdc++.h>
using namespace std;

char matrix[5][5];
map<char, pair<int,int>> pos;

string generateKey() {
    string alph = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    random_shuffle(alph.begin(), alph.end());
    return alph.substr(0,8); // random 8-char key
}

void generateMatrix(string key) {
    set<char> used;
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    int i=0,j=0;
    for(char c:key){
        if(c=='J') c='I';
        if(!used.count(c)){
            matrix[i][j]=c;
            pos[c]={i,j};
            used.insert(c);
            j++;
            if(j==5){ j=0; i++; }
        }
    }
}

string prepare(string text){
    string res="";
    for(char c:text){
        if(c!=' '){
            if(c=='J') c='I';
            res+=toupper(c);
        }
    }

    for(int i=0;i<res.length();i+=2){
        if(i+1==res.length()) res+='X';
        else if(res[i]==res[i+1]) res.insert(i+1,"X");
    }
    return res;
}

string encrypt(string text){
    string cipher="";
    for(int i=0;i<text.length();i+=2){
        char a=text[i], b=text[i+1];
        int r1=pos[a].first, c1=pos[a].second;
        int r2=pos[b].first, c2=pos[b].second;

        if(r1==r2){
            cipher+=matrix[r1][(c1+1)%5];
            cipher+=matrix[r2][(c2+1)%5];
        }
        else if(c1==c2){
            cipher+=matrix[(r1+1)%5][c1];
            cipher+=matrix[(r2+1)%5][c2];
        }
        else{
            cipher+=matrix[r1][c2];
            cipher+=matrix[r2][c1];
        }
    }
    return cipher;
}

string decrypt(string cipher){
    string text="";
    for(int i=0;i<cipher.length();i+=2){
        char a=cipher[i], b=cipher[i+1];
        int r1=pos[a].first, c1=pos[a].second;
        int r2=pos[b].first, c2=pos[b].second;

        if(r1==r2){
            text+=matrix[r1][(c1+4)%5];
            text+=matrix[r2][(c2+4)%5];
        }
        else if(c1==c2){
            text+=matrix[(r1+4)%5][c1];
            text+=matrix[(r2+4)%5][c2];
        }
        else{
            text+=matrix[r1][c2];
            text+=matrix[r2][c1];
        }
    }
    return text;
}

int main(){
    srand(time(0));

    string text;
    cout<<"Enter plaintext: ";
    cin>>text;

    string key = generateKey();

    generateMatrix(key);
    string prepared = prepare(text);

    string enc = encrypt(prepared);

    cout<<"Generated Key: "<<key<<endl;
    cout<<"Encrypted: "<<enc<<endl;
    cout<<"Decrypted: "<<decrypt(enc)<<endl;

    return 0;
}