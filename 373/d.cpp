#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,M;
    cin >> N >> M;
    vector <ll> x(N,0);
    vector <ll> u(M,0);vector <ll> v(M,0);vector <ll> w(M,0);
    vector <ll> order(M,1);
    rep(i,0,M){
        ll U,V,W;
        cin >> U >> V >> W;
        u[i] = U;
        v[i] = V;
        w[i] = W;
        if(U<V){
            order[i] = U;
        }
        else{
            order[i] = V;
        }
        
    }
    rep(i,1,N){
        rep(j,0,M){
            if(order[j] == i){
                 ll U,V,W;
                 U = u[j];
                 V = v[j];
                 W = w[j];
                if(U < V){
                    x[V-1] = x[U-1] + W;
                }
                else{
                    x[U-1] = x[V-1] - W;
                }
            }
        }
    }
    rep(i,0,N){
        if(i!=N-1){
            cout << x[i] << ' ';
        }
        else{
            cout << x[i];
        }
        
    }
    
}