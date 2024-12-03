#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll n;
    ll ans;
    cin >> n;
    vector <ll> A(n),B(n);
    rep(i,0,n){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B.rbegin(),B.rend());
    ll smax = B[1];
    for(ll i = 0; i < n; i ++){
        if(A[i] == smax){
            ans = i+1;
            break;
        }
    }
    cout << ans;
}