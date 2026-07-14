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

bool inside(int x, int y, int h, int w) { return 0 <= x && x < h && 0 <= y && y < w; }

int main() {
    ll T;
    cin >> T;
    vl anss(T);
    rep(_, 0, T) {
        ll X, Y, K;
        cin >> X >> Y >> K;
        if (X == Y) {
            anss[_] = 0;
            continue;
        }
        vl sx;
        vl sy;
        ll x = X;
        while (x / K != 0) {
            sx.push_back(x % K);
            x /= K;
        }
        if(x!=0) sx.push_back(x);
        ll y = Y;
        while (y / K != 0) {
            sy.push_back(y % K);
            y /= K;
        }
        if(y!=0)sy.push_back(y);

        ll yn = sy.size();
        ll xn = sx.size();
        ll same = -1;

        rep(i, 0, min(yn, xn)) {
            if (sy[yn - 1 - i] != sx[xn - 1 - i]) {
                same = i;
                break;
            }
        }
        if (same == -1) {
            same = min(yn, xn);
        }
        anss[_] = xn - same + yn - same;
    }
    rep(i, 0, T) { cout << anss[i] << "\n"; }
}