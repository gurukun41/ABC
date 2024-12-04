#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,T,P;
    cin >> N >> T >> P ;
    P --;
    vector <ll> L(N);
    rep(i,0,N){
        ll a;
        cin >> a;
        L[i] = a;
    }
    sort(L.rbegin(), L.rend());
    ll ans = 0;
    ll target = L[P];
    while(target < T){
        ans ++;
        target ++;
    }
    cout << ans;
}