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

template <class F>
ll binary_search_ll(ll ok, ll ng, F is_ok) {
    while (abs(ok - ng) > 1) {
        ll mid = ok + (ng - ok) / 2;
        if (is_ok(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

ll INF = 1e9;
int main(){
    ll N,K;cin >> N >> K;
    vpl p(N);
    vpl mR(N);
    ll r = 0;
    rep(i,0,N){
        ll L,R;cin >> L >>R;
        p[i] = pl{L,R};
        chmax(r,R);
    }
    sort(all(p));
    mR[N-1] = {N-1,p[N-1].second};

    rep(i,1,N){
        ll num = N-i-1;
        if(mR[N-i].second <= p[N-i-1].second){
            num = mR[N-i].first;
        }
        mR[N-i-1] = {num, min(mR[N-i].second,p[N-i-1].second)};
    }

    ll l = -1;
    while(r-l>1){
        ll m = (r+l)/2;
        bool can = false;
        vl seen(N,0);
        rep(i,0,N){
            ll count = 1;
            ll min = INF;
            ll R = p[i].second;
            ll now = i;
            queue<ll> q;
            while(count < K){
                ll ub = binary_search_ll((ll)N, -1, [&](ll x) {
                    return p[x].first - R >= m;
                });
                if(ub==N)break;
                now = mR[ub].first;
                if(seen[now]){
                    count += seen[now];
                    break;
                }
                count++;
                min = chmin(min, p[now].first-R);
                R = p[now].second;
                q.push(now);
            }
            if(count>=K){
                can = true;
                break;
            } 
            while(!q.empty()){
                count--;
                seen[q.front()] = count;
                q.pop();
            }
        }
        if(can){
            l = m;
        } else {
            r = m;
        }
    }
    if(l==0){
        l = -1;
    }
    cout << l << "\n";
}