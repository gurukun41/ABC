#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)

int main() {
    ll n, k;
    int x;
    cin >> n >> k >> x;
    vector<int> a(n+1,0) ;
    rep(i,0,n+1){
        int b;
        if(i < k){
            cin >> b;
            a[i] = b;
        }
        else if(i == k){
            a[i] = x;
        }
        else{
            cin >> b;
            a[i] = b;
        }
    }
    rep(i,0,n+1){
        cout << a[i] << " ";
    }

}