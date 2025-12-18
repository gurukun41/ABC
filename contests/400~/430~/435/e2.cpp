#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ld = long double;
using mint = atcoder::modint998244353;
using vl = vector<ll>;                                   // long long型の一次元
using vvl = vector<vl>;                                  // long long型の二次元配列
using vvvl = vector<vvl>;                                // long long型の三次元配列
using vi = vector<int>;                                  // int型の一次元
using vvi = vector<vi>;                                  // int型の二次元配列
using vvvi = vector<vvi>;                                // int型の三次元配列
using vb = vector<bool>;                                 // bool型の一次元
using vvb = vector<vb>;                                  // bool型の二次元配列
using vvvb = vector<vvb>;                                // bool型の三次元配列
using vs = vector<string>;                               // string型の一次元
using vvs = vector<vs>;                                  // string型の二次元配列
using pl = pair<ll, ll>;                                 // long long型のペア
using vpl = vector<pl>;                                  // long long型のペアの一次元配列
#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)  // for文の短縮
#define all(v) v.begin(), v.end()                        // all(v)でvの始まりと終わりのイテレーター

// 無限大の値
const long long INF = 1LL << 60;

// 入力を受け取る
template <typename T>
T input() {
    T x;
    cin >> x;
    return x;
}

// a,bのうち最大のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// Yes/Noを出力
void yn(bool a) {
    if (a)
        cout << "Yes\n";
    else
        cout << "No\n";
}

// 素数判定
bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    ll N, Q, L, R;
    set<pair<ll,ll>> st;
    set<pair<ll,ll>>::iterator itr;

    cin >> N >> Q;
    st.insert({N,1});
    ll ans = N;
    rep(i,0,Q) {
        cin >> L >> R;
        itr=st.lower_bound({L,-1});
        vector<pair<ll, ll>> resv;
        while(itr!=st.end()){
            ll sl=(*itr).second;
            ll sr=(*itr).first;
            if(R<sl)break;
            if((sl<L)&&(R<sr)) {
                resv.push_back({L-1,sl});
                resv.push_back({sr,R+1});
            } else if((sl<L)&&(L<=sr)){
                resv.push_back({L-1,sl});
            } else if((R<sr)&&(sl<=R)) {
                resv.push_back({sr,R+1});
            }
            ans-=min(sr,R)-max(sl,L)+1;
            itr=st.erase(itr);
        }
        ll sz = resv.size();
        rep(i,0,sz){
            st.insert(resv[i]);
        }
        cout << ans << "\n";
    }
}