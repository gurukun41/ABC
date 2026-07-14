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

struct MSTDSU {
    vector<int> parent_or_size;

    MSTDSU() {}
    explicit MSTDSU(int n) : parent_or_size(n, -1) {}

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    bool same(int a, int b) {
        return leader(a) == leader(b);
    }

    bool merge(int a, int b) {
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }
};

struct MSTEdge {
    int u, v, id;
    ll cost;

    MSTEdge() {}
    MSTEdge(int u, int v, ll cost, int id = -1) : u(u), v(v), id(id), cost(cost) {}
};

struct MSTResult {
    ll cost;
    vector<int> edge_ids;
    bool connected;
};

MSTResult kruskal(int n, vector<MSTEdge> edges) {
    for (int i = 0; i < (int)edges.size(); i++) {
        if (edges[i].id == -1) edges[i].id = i;
    }
    sort(edges.begin(), edges.end(), [](const MSTEdge& a, const MSTEdge& b) {
        return a.cost < b.cost;
    });

    MSTDSU dsu(n);
    ll cost = 0;
    vector<int> used;
    for (const auto& e : edges) {
        if (!dsu.merge(e.u, e.v)) continue;
        cost += e.cost;
        used.push_back(e.id);
    }
    return {cost, used, (int)used.size() == n - 1};
}

MSTResult prim_mst(const vector<vector<pair<int, ll>>>& g, int start = 0) {
    int n = (int)g.size();
    if (n == 0) return {0, {}, true};

    vector<bool> used(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start});

    ll cost = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (used[v]) continue;
        used[v] = true;
        cost += d;
        cnt++;
        for (auto [to, w] : g[v]) {
            if (!used[to]) pq.push({w, to});
        }
    }
    return {cost, {}, cnt == n};
}

int main(){
    ll T;cin >> T;
    vvl ans(T);
    rep(_,0,T){
        int N,M;cin >> N >> M;
        vector<MSTEdge> edges;
        rep(i,0,M){
            int u,v;cin >> u >> v;
            u--,v--;
            edges.push_back({u, v, 1});
        }
        auto res = kruskal(N, edges);
        vi nv = res.edge_ids;
        vvi v(N);
        rep(i,0,nv.size()){
            MSTEdge e = edges[nv[i]];
            v[e.u].push_back(e.v);
            v[e.v].push_back(e.u);
        }
        queue<pl> q;
        q.push(pl{0,0});
        vl ret(N,-1);
        while(!q.empty()){
            pl now = q.front();
            q.pop();
            ll p = now.first;
            ll va = now.second;
            if(ret[p] != -1)continue;
            ret[p] = va;
            for(int ne : v[p]){
                if(ret[ne] == -1){
                    q.push(pl{ne,va+1});
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