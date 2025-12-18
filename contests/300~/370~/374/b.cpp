#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    string S,T;
    bool dif= false;
    cin >> S >> T;
    ll size_s = S.size(),size_t = T.size();
    ll size = min(size_s,size_t);
    if(S==T){
        cout << 0;
    }
    
    else{
        rep(i,0,size){
            if(S[i] != T[i]){
                dif = true;
                cout << i+1 ;
                break;
            }
        }
        if(!dif){
            cout << size+1;
        }
    }
    
    
    
    
}