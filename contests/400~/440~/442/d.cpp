#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ld = long double;
using mint = atcoder::modint998244353;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vvs = vector<vs>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define all(v) v.begin(), v.end()

template <typename T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void yn(bool a) {
    if (a)
        cout << "Yes\n";
    else
        cout << "No\n";
}

using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }

int main(){
    ll N,Q;cin >> N >> Q;
    atcoder::segtree<S, op, e> seg(N);
    rep(i,0,N) {
        ll a;cin >> a;
        seg.set(i,a);
    }

    rep(_,0,Q){
        ll q;cin >> q;
        if(q==1){
            ll x; cin >> x;
            x--;
            ll f = seg.get(x);
            ll s = seg.get(x+1);
            seg.set(x, s);
            seg.set(x+1,f);
        } else {
            ll l,r;cin >> l >> r;
            l--;
            cout << seg.prod(l,r) << "\n";
        }
    }
}