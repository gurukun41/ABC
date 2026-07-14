#include <bits/stdc++.h>
#include <atcoder/all>
#include <queue>
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

template <typename T>
vector<T> read_vector(int n) {
    vector<T> a(n);
    rep(i, 0, n) cin >> a[i];
    return a;
}

template <typename T>
vector<vector<T>> read_matrix(int h, int w) {
    vector<vector<T>> a(h, vector<T>(w));
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
    return a;
}

template <typename T>
void print_vector(const vector<T> &v, string sep = " ", string end = "\n") {
    rep(i, 0, v.size()) {
        if (i) cout << sep;
        cout << v[i];
    }
    cout << end;
}

template <typename T>
void print_lines(const vector<T> &v) {
    for (const T &x : v) cout << x << "\n";
}

bool inside(int x, int y, int h, int w) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

int main(){
    ll T;cin >> T;
    vvl ans(T);
    rep(_,0,T){
        int N,M;cin >> N >> M;
        vvl V(N);
        rep(i,0,M){
            int u,v;cin >> u >> v;
            u--,v--;
            V[u].push_back(v);
            V[v].push_back(u);
        }
        vl ret(N,-1);
        stack<pl> q;
        q.push(pl{0,0});
        while(!q.empty()){
            pl now = q.top();
            q.pop();
            ll p = now.first;
            ll va = now.second;
            if(ret[p] != -1) continue;
            ret[p] = va;
            for(ll ne : V[p]){
                if(ret[ne]==-1){
                    q.push({ne,va+1});
                }
            }
        }
        ans[_] = ret;

    }
    rep(i,0,T){
        rep(j,0,ans[i].size()){
            cout << ans[i][j];
            if(j != ans[i].size()-1){
                cout << " ";
            }
        }
        cout << "\n";
    }
}