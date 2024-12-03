#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,X,Y;
    cin >> N >> X >> Y;
    vector<ll> a(N),b(N);
    rep(i,0,N){
        cin >> a[i];
    }
    rep(i,0,N){
        cin >> b[i];
    }
    ll ama=0;
    ll sho=0;
    ll ans=N;
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    for(ll i = 0; i < N; i++){
            ama += a[i];
            if(ama > X){
                ans = i+1;
                break;
            }
    }
    for(ll i = 0; i < N; i++){
            sho += b[i];
            if(sho > Y && i < ans -1){
                ans = i+1;
                break;
            }
    }
    cout << ans;
}