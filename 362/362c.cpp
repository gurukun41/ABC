#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll n; 
    ll x =0;
    ll d=0;
    cin >> n ;
    vector<ll> L(n),R(n),X(n),D(n);
    for(ll i = 0; i < n ; i++){
        ll a,b;
        cin >> a >> b;
        L[i] = a;
        R[i] = b;
        X[i] = a;
        D[i] = b-a;
        x += a;
        d += (b-a);
    }
    if(x + d < 0 || x > 0){
        cout << "No";
    }
    else{
        for(ll i = 0 ; i < n && x < 0;i++){
            ll di = D[i];
            x += di;
            X[i] += di;
            if(x > 0){
                for(ll j = 0; j < di && x > 0 ; j++){
                    x --;
                    X[i] --;
                }
            }
        }
        cout << "Yes" << endl;
        rep(i,0,n){
            cout << X[i] << " ";
        }
    }
}