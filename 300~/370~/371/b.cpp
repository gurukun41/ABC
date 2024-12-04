
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,M,A;
    char B;
    cin >> N >> M;
    vector <bool> taro(N,0);
    rep(i,0,M){
        cin >> A >> B;
        if(taro[A-1] == 0 && B == 'M'){
            taro[A-1] = 1;
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }
}