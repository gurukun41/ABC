#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N;
    ll M = 0;
    cin >> N;
    vector <string> S(N);
    vector <ll> Slen(N);
    rep(i,0,N){
        cin >> S[i];
        ll len = S[i].length();
        Slen[i] = len-1;
        if(M < len){
            M = len;
        }
    }
    rep(j,0,M){
        ll non =0;
        for(ll i = N-1; i > -1; i--){
            if(i != 0 && N != 1){
                if(j > Slen[i]){
                    non++;
                }
                else{
                    rep(k,0,non){
                        std::cout << "*";
                    }
                    non = 0;
                    std::cout << S[i][j];
                }
            }
            else{
                if(j > Slen[i]){
                    non = 0;
                    std::cout << "\n" ;
                }
                else{
                    rep(k,0,non){
                        std::cout << "*";
                    }
                    non = 0;
                    std::cout << S[i][j] << "\n";
                }
            }
        }
    }
}