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
    vector<string> ans(T);
    rep(_,0,T){
        ll N,C;cin >> N >> C;
        C--;
        vs s(N);
        rep(i,0,N){
            cin >> s[i];
        }
        vector<vpl> dp(N,vpl(N));
        for(ll i=N-1; i >= 0; i--){
            rep(j,0,N){
                if(i == N-1){
                    if(j ==C){
                        dp[i][j] = pl{1,1};
                    } else {
                        dp[i][j] = pl{0,(s[i][j] == '.')};
                    }
                } else {
                    if(s[i][j] == '.'){
                        dp[i][j] = dp[i+1][j];
                    } else {
                        if(dp[i+1][j].first){
                            dp[i][j] = dp[i+1][j];
                            dp[i][j].first = dp[i][j].second;
                        } else {
                            dp[i][j] = pl{0,0};
                        }
                    }
                    if(dp[i][j].first == 0){
                        if(s[i+1][j] == '#'){
                            dp[i][j].second = 0;
                        }
                        if(j-1>=0){
                            if(dp[i+1][j-1].first){
                                if(s[i][j] == '.'){
                                    dp[i][j].first = 1;
                                    continue;
                                } else if(dp[i+1][j].second){
                                    // 壁であるが、それより下が壁なし
                                    dp[i][j] = pl{1,1};
                                    continue;
                                }
                            }
                        }
                        if(j+1<N){
                            if(dp[i+1][j+1].first){
                                if(s[i][j] == '.'){
                                    dp[i][j].first = 1;
                                    continue;
                                } else if(dp[i+1][j].second){
                                    // 壁であるが、それより下が壁なし
                                    dp[i][j] = pl{1,1};
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
        }

        string out = "";
        rep(i,0,N){
            if(dp[0][i].first){
                out += '1';
            } else {
                out += '0';
            }
        }
        ans[_] = out;
    }
    rep(i,0,T){
        cout << ans[i] << "\n";
    }
}