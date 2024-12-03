#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N;
    cin >> N;
    vector<ll> K(N);
    ll sumK = 0;
    rep(i,0,N){
        ll k;
        cin >> k;
        K[i] = k;
        sumK += k;
    }
    ll ans = sumK;
    if(sumK%2==0){
        sumK /=2;
    }
    else{
        sumK = sumK/2 +1;
    }
    sort(K.begin(),K.end());
    do{
        ll sum=0;
        rep(i,0,N){
            if(ans == sumK){
                break;
            }
            sum += K[i];
            if(sum >= sumK){
                if(ans > sum){
                    ans = sum;
                }
                break;
            }
        }
    } while(next_permutation(K.begin(),K.end()));
    cout << ans;
}