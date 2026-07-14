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
    ll X;cin >> X;
    ll Q;cin >> Q;
    priority_queue<ll> max_pq;//左
    priority_queue<ll, vl, greater<ll>> min_pq;//右
    vl ans(Q);
    rep(_,0,Q){
        ll A,B;cin >> A >> B;
        if(A>B){
            ll temp = A;
            A =B;
            B=temp;
        }
        if(A<X&&X<B){
            min_pq.push(B);
            max_pq.push(A);
        } else if(X < A){
            max_pq.push(X);
            X=A;
            min_pq.push(B);
            if(X>min_pq.top()){
                X = min_pq.top();
                min_pq.pop();
                min_pq.push(A);
            }
        } else{
            min_pq.push(X);
            X=B;
            max_pq.push(A);
            if(X<max_pq.top()){
                X = max_pq.top();
                max_pq.pop();
                max_pq.push(B);
            }            
        }
        ans[_] = X;
    }
    rep(i,0,Q){
        cout << ans[i] << "\n";
    }
}