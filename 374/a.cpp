#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    string S;
    ll ans=0;
    rep(i,0,12){
        cin >> S;
        if(S.length()== i+1){
            ans++;
        }
    }
    cout << ans;
    
}