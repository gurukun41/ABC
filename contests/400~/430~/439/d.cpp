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

int main(){
    ll N,Q;cin >> N >> Q;
    vl A(N);rep(i,0,N) cin >> A[i];
    sort(all(A));
    rep(_,0,Q){
        ll X,Y;cin >> X >> Y;
        ll l = -1, r = N;
        while(r-l>1){
            ll m = (r+l)/2;
            if(A[m] >= X){
                r = m;
            }else{
                l = m;
            }
        }
        ll m0 = l;
        l = -1, r = N;
        while(r-l>1){
            ll m = (r+l)/2;
            if(A[m] >= X+Y-1){
                r = m;
            }else{
                l = m;
            }
        }
        ll m1 = l;
        ll l2 = 0, r2 = N-m0;
        while(r2-l2>1){
            ll m2 = (r2+l2)/2;
            l = -1, r = N;
            while (r-l>1){
                ll m = (r+l)/2;
                if(A[m] > X+Y-1+m2){
                    r = m;
                }else{
                    l = m;
                }
            }
            ll mt = r;
            if(mt -m1 < m2){
                r2 = m2;
            } else {
                l2 = m2;
            }
        }
        ll k = l2;
        
        cout << X+Y-1+k << "だ\n";
    }
}