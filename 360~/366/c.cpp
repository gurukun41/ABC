#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll Q;
    cin >> Q;
    vector <vector <ll>> X(1000000, vector<ll>(1,0));
    ll valX=0;
    rep(i,0,Q){
        ll query,x;
        cin >> query;
        if(query == 1){
            cin >> x;
            if (X[x-1][0] == 0){
                valX ++;
            }
            X[x-1][0] ++;
        }
        else if(query == 2){
            cin >> x;
            X[x-1][0] --;
            if ( X[x-1][0] == 0){
                valX --;
            }
        }
        else{
            cout << valX << "\n";
        }
    }
}