#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,Mg,Mh,u,v,a;
    ll ans = 0;
    cin >> N >> Mg;
    vector <vector<bool>> G(N+1,vector<bool>(N+1,0));
    rep(i,0,Mg){
        cin >> u >> v;
        G[u][v] = 1;
    }
    vector <vector<bool>> H(N+1,vector<bool>(N+1,0));
    cin >> Mh;
    rep(i,0,Mh){
        cin >> u >> v;
        H[u][v] = 1;
    }
    vector < vector<ll>> A(N+1,vector<ll>(N+1,0));
    rep(i,1,N){
        rep(j,i+1,N+1){
            cin >> a;
            A[i][j] = a;
        }
    }
    rep(i,1,N){
        rep(j,i+1,N+1){
            if(G[i][j] != H[i][j]){
                ans += A[i][j];
                cout << i << j << endl;
            }
        }
    }
    cout << ans;
}