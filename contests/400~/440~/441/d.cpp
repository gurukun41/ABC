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
    ll N,M,L,S,T;cin >> N >> M >> L >> S >> T;
    vector<vpl> v(N);
    rep(i,0,M){
        ll U,V,C;cin >> U >> V >>C;
        U--;V--;
        v[U].push_back(pl{V,C});
    }
    set<ll> ans;

    auto dfs = [&](this auto& self, ll p, ll c, ll sum) -> ll {
        if(c == L){
            if(S <= sum && sum <= T){
                ans.insert(p);
            }
        } else {
            for(pl pair:v[p]){
                self(pair.first, c+1, sum+pair.second);
            }
        }
        return 0;
    };    
    dfs(0,0,0);
    bool first = true;
    for(auto o:ans){
        if(!first){
            cout << " ";
        } else {
            first = false;
        }
        cout << o+1;
    }
    cout << "\n";
}