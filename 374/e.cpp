#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N, X;
    cin >> N >> X;
    vector<vector<ll>> M(4,vector<ll>(N));
    rep(i,0,N){
        cin >> M[0][i] >> M[1][i] >> M[2][i] >> M[3][i];
    }
    
}