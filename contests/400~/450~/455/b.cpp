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
    ll H,W;cin >> H >> W;
    vs S(H);rep(i,0,H) cin >> S[i];
    ll ans = 0;
    rep(i,0,H){
        rep(j,0,W){
            rep(i2,i,H){
                rep(j2,j,W){
                    bool can = true;

                    rep(x,0,i2-i+1){
                        rep(y,0,j2-j+1){
                            if(S[i+x][j+y] != S[i2-x][j2-y]){
                                can =false;
                            }
                        }
                    }
                    if(can){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}