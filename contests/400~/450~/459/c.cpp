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
    ll N,Q;cin >> N >> Q;
    vl V(N,0);
    atcoder::fenwick_tree<ll> fw(Q+2);
    fw.add(0,N);
    vl ans;
    ll min = 0;
    rep(_,0,Q){
        ll q;cin >> q;
        if(q==1){
            ll x;cin >> x;
            x--;
            V[x]++;
            fw.add(V[x],1);
            fw.add(V[x]-1,-1);
            if(min==V[x]-1&&fw.sum(min,min+1)==0){
                min++;
            }

        } else {
            ll y;cin >> y;

            y+=min;
            if(y>Q+2){
                ans.push_back(0);
            }else{
                ans.push_back(fw.sum(y,Q+2));
            }
        }
    }
    rep(i,0,ans.size()){
        cout << ans[i] << "\n";
    }
}