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
    std::random_device seed_gen;
    std::uint32_t seed = seed_gen();
    std::mt19937 engine(seed);
    ll N,M;cin >> N >> M;
    vs S(N);
    rep(i,0,N){
        cin >> S[i];
    }
    cout << "----\n";


    ll ans = -1;
    vl anss;

    for (ll s = 0; s < 1<<(M); s++){
        vl check(N,0);
        rep(i,0,N){
            rep(j,0,M){
                char c = '0';
                if((s>>(M-1-j))%2==1){
                    c = '1';
                }
                if(c == S[i][j]){
                    check[i] = true;
                    break;
                }
            }
        }
        ll can = 1;
        rep(i,0,N){
            if(!check[i]){
                can = 0;
                break;
            }
        }
        if(can){
            ans = s;
            anss.push_back(s);
        }
    }
    if(ans == -1){
        cout << "No" << "\n";
        return 0;
    }
    rep(i,0,anss.size()){
        cout << static_cast<std::bitset<3> >(anss[i]) << endl;    
    }
}