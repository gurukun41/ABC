#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,K;
    string first_S;
    cin >> N >> K >> first_S;
    vector <char> S(N);
    vector <char> beforeS(N);
    rep(i,0,N){
        S[i] = first_S[i];
    }
    beforeS = S;
    ll wide = N-K;
    ll ans = 0;
    sort(S.begin(),S.end());
    do {
        bool same=false;
        bool dekiru = false;
        if(S == beforeS){
            same = true;
            continue;
        }
        else{
            beforeS = S;
            for(ll i = 0; i <= wide;i++){
                if(same || dekiru){
                    break;
                }
                else{
                    ll num = 0;
                    for(ll j = 1; j <= (K+1)/2; j++){
                        if(S[i+j-1] == S[i+K-j]){
                            num++;
                        }
                        if(num == (K+1)/2){
                            dekiru = true;
                            num =0;
                            break;
                        }
                        if(j == (K+1)/2){
                            num = 0;
                        }
                    }
                }
            }
            if(!dekiru){
                ans ++;
            }
        }
    }while(next_permutation(S.begin(),S.end()));
    
    std::cout << ans;
}