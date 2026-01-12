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
    ll T;cin >> T;
    vl ans(T);
    rep(_,0,T){
        ll N, W;cin >> N >> W;
        vl C(N+1,0);
        rep(i,0,N) {
            cin >> C[i+1];
            C[i+1] += C[i];
        }
        ll Min = 1LL << 60;

        rep(i,1,W+1){
            ll temp = 0;
            for(ll j = i; j <= N; j += 2*W){
                ll f = min(j+W-1, N);
                temp += C[f]-C[j-1];
            }
            chmin(Min,temp);
            chmin(Min,C[N]-temp);
        }
        ans[_] = Min;
    }
    rep(i,0,T){
        cout << ans[i] << "\n";
    }
}