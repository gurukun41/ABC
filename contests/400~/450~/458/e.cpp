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

struct Combination {
    vector<mint> fact, ifact; // fact:階乗, ifact:階乗の逆元

    // コンストラクタ: nまでの階乗とその逆元を前計算する
    Combination(ll n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (ll i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        
        ifact[n] = fact[n].inv();
        
        for (ll i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    // nCk (組み合わせ)
    mint operator()(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }

    // nPk (順列)
    mint P(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[n - k];
    }

    // nHk (重複組み合わせ)
    mint H(ll n, ll k) {
        if (n == 0 && k == 0) return 1;
        return (*this)(n + k - 1, k);
    }
};

int main(){
    vl X(4);cin >> X[1] >> X[2] >> X[3];
    if(X[1] < X[3]){
        ll temp = X[1];
        X[1] = X[3];
        X[3] = temp;
    }
    mint ans = 0;
    Combination C(X[1]+X[2]+X[3]+10);
    if(X[1] >= X[3] ){
        ll i = X[3];

        while(i > 0){
            if(X[1]!=i && X[2] >= 2*i){
                //     残りで2を入れるかず                // i個の3が何通りか 
                ans += C(X[1]+X[3]+X[2]-2*i, X[2]-2*i)*C(X[1]-1,i)*C(X[3]-1,i-1);
                //cout << ans.val() << "\n";
            }
            if(X[2] >= 2*i-1){
                ans += C(X[1]+X[3]+X[2]-2*i+1, X[2]-2*i+1)*C(X[1]-1,i-1)*C(X[3]-1,i-1)*2;
                //cout << ans.val() << "\n";
            }
            if(X[3]>=2&& X[2] >= 2* i-2){
                ans += C(X[1]+X[3]+X[2]-2*i+2, X[2]-2*i+2)*C(X[1]-1,i-2)*C(X[3]-1,i-1);
                //cout << ans.val() << "\n";
            }
            i--;
        }
    }
    cout << ans.val() << "\n";
}