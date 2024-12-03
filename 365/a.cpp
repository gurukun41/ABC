#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll Y;
    cin >> Y;
    ll ans;
        if(Y%4 != 0){
            ans = 365;
        }
        else if(Y%100 != 0){
            ans =  366;
        }
        if(Y%100 == 0 && Y%400 != 0){
            ans = 365;
        }
    if(Y%400 == 0){

        ans = 366;
    }
    cout << ans;
}