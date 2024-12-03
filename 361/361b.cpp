#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll a,b,c,d,e,f,g,h,i,j,k,l;
    cin >> a >> b >> c >> d >> e >> f 
    >> g >> h >> i >> j >> k >> l;
    if((j <= a||k <= b||l <= c) || (d<=g||e<=h||f<=i)){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
}