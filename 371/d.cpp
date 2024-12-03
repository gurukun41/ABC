#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N;
    cin >> N;
    vector <ll> X(N+2,0);
    X[N+1] = 1000000000;
    X[0] = -100000000;
    rep(i,1,N+1){
        cin >> X[i];
    }
    vector <ll> P(N+2,0);
    rep(i,1,N+1){
        cin >> P[i];
    }
    ll sum = 0;
    rep(i,1,N+1){
        sum += P[i];
        P[i] = sum;
    }
    P[N+1] = sum;
    ll Q,L,R;
    cin >> Q;
    rep(i,0,Q){
        cin >> L >> R;
        ll max,min;
        ll ngl = 0,okl = N+1;
        while(okl - ngl > 1){
            ll m = (okl+ngl)/2;
            if(X[m] >= L){
                okl = m;
            }
            else{
                ngl = m;
            }
        }
        min = P[okl-1];
        ll okr = 0,ngr = N+1;
        while(ngr -okr >1){
            ll m = (okr+ngr)/2;
            if(X[m] <= R){
                okr = m;
            }
            else{
                ngr = m;
            }
        }
        max = P[okr];
        cout << max - min << "\n";
    }
}