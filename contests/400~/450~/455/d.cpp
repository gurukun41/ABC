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
    ll N, Q;cin >> N >> Q;
    vl C(Q), P(Q);
    rep(i,0,Q){
        cin >> C[i] >> P[i];
        C[i]--;
        P[i]--;
    }
    vl end(N,1);
    vvl v(N,vl(0));
    for(ll i = Q-1; i >= 0; i--){
        if(end[C[i]] && v[P[i]].size() == 0){
            // つなげる
            v[P[i]].push_back(C[i]);
            end[C[i]] = 0;
        }
    }
    rep(i,0,N){
        if(end[i]==0){
            cout << 0;
        }else{
            ll ans = 1;
            ll p = i;
            while(true){
                if(v[p].size() == 0){
                    break;
                }
                p = v[p][0];
                ans++;
            }
            cout << ans;
        }
        if(i != N-1){
            cout << " ";
        }else{
            cout << "\n";
        }
    }
}