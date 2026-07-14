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

const ll DIJKSTRA_INF = 4e18;

ll Y;

vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& g, int s) {
    int n = (int)g.size();
    vector<ll> dist(n, DIJKSTRA_INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, cost] : g[u]) {
            if (dist[v] <= d + cost) continue;
            dist[v] = d + cost;
            pq.push({dist[v], v});
        }
    }
    return dist;
}

int main(){
    ll N,M;cin >> N >> M >> Y;
    vector<vector<pair<int,ll>>> g(N+2);
    rep(i,0,M){
        ll u, v, T;cin >> u >> v >> T;
        u--,v--;
        g[u].push_back({v,T});
        g[v].push_back({u,T});
    }
    vl X(N);
    rep(i,0,N){
        cin >> X[i];
        g[i].push_back({N,X[i]});
        g[N+1].push_back({i,X[i]});
    }
    g[N].push_back({N+1,Y});
    auto dist = dijkstra(g, 0);
    rep(i,1,N){
        cout << dist[i];
        if(i != N-1){
            cout << " ";
        } else{
            cout << "\n";
        }
    }
}