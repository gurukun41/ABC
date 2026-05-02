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
    vvl g(N);
    rep(i,0,M){
        ll A,B;cin >> A >> B;
        A--;B--;
        g[A].push_back(B);
    }
    queue<ll> q;
    vl seen(N,0);
    q.push(0);
    seen[0] = 1;
    ll ans = 1;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(ll v:g[u]){
            if(seen[v]) continue;
            //動作
            seen[v] = 1;
            ans++;
            q.push(v);
        }        
    }
    cout << ans << "\n";
}