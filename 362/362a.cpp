#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll a,b,c;
    string d;
    cin >> a >> b >> c >> d ;
    if(d == "Red"){

        cout << min(b,c);
    }
    else if(d == "Green"){
        cout << min(a,c);
    }
    else{
        cout << min(a,b);
    }
}