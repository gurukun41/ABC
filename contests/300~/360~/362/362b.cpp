#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll xa,ya,xb,yb,xc,yc,lab,lbc,lca;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    lab = (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb);
    lbc = (xb-xc)*(xb-xc) + (yb-yc)*(yb-yc);
    lca = (xc-xa)*(xc-xa) + (yc-ya)*(yc-ya);
    if((lab + lbc == lca)||(lbc + lca == lab) ||(lca + lab == lbc) ){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}