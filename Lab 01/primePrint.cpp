#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define l long
#define d double
#define ld long double

void solve() {
    vector<bool> arr(1001,true);
    arr[0]=arr[1]=false;
    for (int i = 2; i <= 1000; i++) {
        if(arr[i]==true){
            int cnt=2;
            while(i*cnt<=1000){
                arr[i*cnt]=false;
                cnt++;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=1000;i++){
        ans+=arr[i];
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}