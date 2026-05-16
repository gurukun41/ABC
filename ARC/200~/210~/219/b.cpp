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

int main(){
    ll T;cin >> T;
    vector<mint> ans(T,0);
    rep(_,0,T){
        ll N;cin >> N;
        vl P(N);rep(i,0,N)cin >> P[i];
        vl maxPL(N);
        maxPL[0] = P[0];
        rep(i,1,N){
            maxPL[i] = P[i];
            chmax(maxPL[i],maxPL[i-1]);
        }
        vl minPR(N);
        minPR[N-1] = P[N-1];
        rep(i,1,N){
            minPR[N-1-i] = P[N-1-i];
            chmin(minPR[N-1-i],minPR[N-1-i+1]);
        }
        mint len = N;
        rep(i,0,N-1){
            if(maxPL[i] > minPR[i+1]){
                len = i;
                break;
            }
        }
        if(len.val()==N){
            ans[_] = (len-1)*len/2+1;
        } else {
            ans[_] = (N-1)*N/2 - (N-len-1)*(N-len)/2;
        }
    }
    rep(i,0,T){
        cout << ans[i].val() << "\n";
    }
}