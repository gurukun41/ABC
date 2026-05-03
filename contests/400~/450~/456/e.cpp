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
ll W;

ll bfs_dist(const vector<vector<ll>>& g, ll s, vs& str, set<pl>& ist) {
    set<pl> st;
    queue<pl> q;
    st.insert(pl{s,0});
    q.push(pl{s,0});

    while (!q.empty()) {
        pl u = q.front();
        q.pop();
        for (ll v : g[u.first]) {
            // 平日か訪問済み
            if (str[v][(u.second+1)%W] == 'x'|| st.contains(pl{v,u.second+1})) continue;

            st.insert(pl{v,u.second+1});
            if(u.second == W-1){

                if(s==v){
                    return 1;
                }
                pl in = pl{s,v};
                ist.insert(in);
                continue;
            }
            q.push(pl{v, u.second+1});
        }
    }

    return 0;
}

vector<int> topological_sort(const vector<vector<ll>>& g) {
    int n = (int)g.size();
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) return {};
    return order;
}

int main(){
    ll T;cin >> T;
    vl ans(T,0);
    rep(_,0,T){
        ll N,M;cin >> N >> M;
        vpl load(M);
        vvl V(N);
        rep(i,0,M){
            ll u,v;cin >> u >> v;
            u--;v--;
            V[u].push_back(v);
            V[v].push_back(u);
        }
        cin >> W;
        vs S(N);
        rep(i,0,N){
            cin >> S[i];
            V[i].push_back(i);
        }


        set<pl> st;
        rep(i,0,N){
            if(ans[_]) break;
            if(S[i][0] == 'o'){
                if(bfs_dist(V,i,S,st)){
                    ans[_] = 1;
                }
            }
        }
        vvl V2(N);
        if(!ans[_]){
            for(pl p:st){
                V2[p.first].push_back(p.second);
            }
            if(topological_sort(V2).size() != N){
                ans[_] = 1;
            }
        }

    }
    rep(i,0,T){
        yn(ans[i]);
    }
}