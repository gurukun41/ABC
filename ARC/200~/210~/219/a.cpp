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
    ll N,M;cin >> N>> M;
    vs S(N);
    rep(i,0,N){
        cin >> S[i];
    }
    set<string> st;
    vl del(N,0);
    ll count = 0;
    rep(i,0,N){
        if(st.contains(S[i])){
            del[i] = 1;
            count++;
        } else {
            st.insert(S[i]);
        }
    }
    if(M<15&&N-count == 1<<M){
        cout << "No" << "\n";
        return 0;
    }
    vs S2;
    rep(i,0,N){
        if(del[i])continue;
        S2.push_back(S[i]);
    }
    string out = "";
    vl can(N-count,0);
    rep(j,0,M){
        ll c1 = 0;
        ll c0 = 0;
        rep(i,0,N-count){
            if(can[i])continue;
            if(S2[i][j] == '0'){
                c0++;
            }else{
                c1++;
            }
        }
        if((c0>=c1)){
            out+='0';
        }else if((c0<c1)){
            out+='1';
        }        
        rep(i,0,N-count){
            if(can[i])continue;
            if(S2[i][j] == '0'&&(c0>=c1)){
                can[i] =1;
            }else if(S2[i][j] == '1'&&(c0<c1)){
                can[i] = 1;
            }
        }        
    }
    cout << "Yes\n";
    cout << out << "\n";
    
}