#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll r;
    cin >> r;
    if(r<100){

        cout << 100-r;
    }
    else if(r<200){
        cout << 200-r;
    }
    else{
        cout << 300-r;
    }
}