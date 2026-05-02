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
    ll N,M;cin >> N >> M;
    vl F(N);rep(i,0,N) cin >> F[i];
    set<ll> s;rep(i,0,N) s.insert(F[i]);
    if(s.size() != N){
        cout << "No" << "\n";
    } else {
        cout << "Yes\n";
    }
    vl ch(M,0);
    rep(i,0,N){
        ch[F[i]-1] = 1;
    }
    rep(i,0,M){
        if(!ch[i]){
            cout << "No\n";
            return 0;
        } 
    }
    cout << "Yes\n";
}