#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,M;
    ll ans = 0;
    cin >> N >> M;
    vector <ll> A(N +1);
    A[0] = 0;
    ll sumA = 0;
    rep(i,1,N+1){
        ll a;
        cin >> a;
        sumA =  (sumA + a % M) % M;
        A[i] = sumA;
    }
    rep(s,1,N+1){
        for(ll t = s+1; t < N+1 ; t++){
                if(A[t-1] == A[s-1]){
                    ans ++;
                }
                if((A[s-1] + sumA)%M == A[t-1]){
                    ans ++;
                }
        }
    }
    std::cout << ans;
}