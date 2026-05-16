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
    ll N,M;cin >> N >> M;
    vpl P(M);
    vpl PR(M);
    vl exl(N+1,0);
    vl exr(N+1,0);
    vl kai(N+1, LLONG_MAX);
    rep(i,0,M){
        ll l,r;cin >> l >> r;
        P[i] = pl{l,r};
        PR[i] = pl{r,l};
        chmin(kai[l],r);
        exl[l] = 1;
        exr[r] = 1;
    }
    rep(i,1,N){
        chmin(kai[N-i],kai[N-i+1]);
    }
    sort(all(P));
    sort(all(PR));
    ll Q;cin >> Q;
    vl ans(Q,0);
    rep(_,0,Q){
        ll S,T;cin >> S >> T;
        if(!exl[S]||!exr[T]) continue;
        ll Ll = -1, Lr = M;
        //正しいはず
        while(Lr-Ll>1){
            ll c = (Ll + Lr)/2;
            if(P[c].first <= S){
                if(P[c].first == S && P[c].second > T){
                    Lr =c;
                }else{
                    Ll = c;
                }
            } else {
                Lr = c;
                
            }
        }

        // 正しいはず
        ll Rl = -1, Rr = M;
        while(Rr-Rl>1){
            ll c = (Rl + Rr)/2;
            if(PR[c].first < T){
                Rl = c;
            } else {
                if(PR[c].first == T && PR[c].second < S){
                    Rl = c;
                } else{
                    Rr = c;
                }
            }
        } 
        if(Rr >= M)continue;
        if(Ll == -1) continue;

        // 反転
        pl pre =  PR[Rr];
        pre = pl{pre.second,pre.first}; 

        // 枠外じゃないか
        if(P[Ll].first != S || P[Ll].second > T){
            continue;
        }
        if(pre.second != T || pre.first < S){
            continue;
        }

        // 同一個体
        if(P[Ll]==pre){
            if(Ll-1>=0 && P[Ll-1].first ==S){
                ans[_] = 1;
            } else if(Rr+1<M && PR[Rr+1].first == T){
                ans[_] = 1;
            } else if(S+1<=N && kai[S+1] < T){
                ans[_] = 1;
            }
        } else {
            if(P[Ll].second <= T && PR[Rr].second >= S
                && P[Ll].second >= PR[Rr].second-1){
                ans[_] = 1;
            }
        }
    }
    rep(i,0,Q){
        yn(ans[i]);
    }
}
