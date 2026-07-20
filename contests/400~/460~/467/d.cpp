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
    ll T;scan(T);
    vs ans(T);
    rep(_,0,T){
        pl P,Q,R,S;scan(P,Q,R,S);
        pl v1 = pl{Q.second-P.second, P.first-Q.first};
        pl v2 = pl{S.second-R.second, R.first-S.first};
        if(v1.first * v2.second != v1.second * v2.first){
            ans[_] = "Yes";
        } else {
            pl K = pl{P.first+Q.first,P.second+Q.second};
            pl L = pl{R.first+S.first, R.second+S.second};

            if((L.first-K.first)*v1.second == (L.second-K.second)*v1.first ){
                ans[_] = "Yes";
            }else{
                ans[_] = "No";
            }
        }
    }
    rep(i,0,T){
        cout << ans[i] << "\n";
    }
}