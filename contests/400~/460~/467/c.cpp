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

template <typename Range>
void yns(const Range &xs) {
    for (const auto &x : xs) yn(x);
}

struct Scanner {
    template <typename T>
    void read(T &x) const {
        cin >> x;
    }

    template <typename T, typename U>
    void read(pair<T, U> &p) const {
        read(p.first);
        read(p.second);
    }

    template <typename T, size_t N>
    void read(array<T, N> &a) const {
        for (T &x : a) read(x);
    }

    template <typename T>
    void read(vector<T> &v) const {
        for (T &x : v) read(x);
    }

    void read(vector<bool> &v) const {
        for (size_t i = 0; i < v.size(); i++) {
            bool x;
            cin >> x;
            v[i] = x;
        }
    }

    template <typename... Ts>
    void operator()(Ts &...xs) const {
        (read(xs), ...);
    }
};

inline constexpr Scanner scan{};

struct Printer {
    template <typename T, typename U>
    void operator()(const pair<T, U> &p, string_view sep = " ", string_view end = "\n") const {
        cout << p.first << sep << p.second << end;
    }

    template <typename Range>
    void operator()(const Range &xs, string_view sep = " ", string_view end = "\n") const {
        bool first = true;
        for (const auto &x : xs) {
            if (!first) cout << sep;
            first = false;
            cout << x;
        }
        cout << end;
    }
};

inline constexpr Printer print{};

template <typename Range>
void prints(const Range &xs) {
    for (const auto &x : xs) cout << x << '\n';
}

bool inside(int x, int y, int h, int w) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

int main(){
    ll N,M;scan(N,M);
    vl A(N);scan(A);
    vl A2 = A;
    vl B(N-1);scan(B);
    vl goal(N);
    goal[0] = 0;
    rep(i,0,N-1){
        goal[i+1] = goal[i];
        if(B[i]==1){
            goal[i+1]+=1;
            goal[i+1]%=2;
        }
    }
    vl goa(N);
    goa[0] = 1;
    rep(i,0,N-1){
        goa[i+1] = goa[i];
        if(B[i]==1){
            goa[i+1]+=1;
            goa[i+1]%=2;
        }
    }
    ll ans = 0;
    rep(i,0,N){
        if(goal[i] != A[i]%2){
            ans++;
        }
    }
    ll ans2 = 0;
    rep(i,0,N){
        if(goa[i] != A2[i]%2){
            ans2++;
        }
    }
    chmin(ans,ans2);
    cout << ans << "\n";
}