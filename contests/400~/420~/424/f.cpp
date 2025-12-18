#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;                                   // long long型の一次元
using vvl = vector<vl>;                                  // long long型の二次元配列
using vvvl = vector<vvl>;                                // long long型の三次元配列
using vi = vector<int>;                                  // int型の一次元
using vvi = vector<vi>;                                  // int型の二次元配列
using vvvi = vector<vvi>;                                // int型の三次元配列
#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)  // for文の短縮
#define all(v) v.begin(), v.end()                        // all(v)でvの始まりと終わりのイテレーター

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

ll search(vvl &M) {
    ll ret = 0;
    rep(i, 0, M.size() - 1) {
        rep(j, 0, M[i].size() - 1) {
            if (M[i][j] == '#' && M[i][j + 1] == '#' && M[i + 1][j] == '#' && M[i + 1][j + 1] == '#') {
                M[i + 1][j + 1] = '.';
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    ll N,Q;cin >> N >> Q;
    vl X = {};
    rep(_,0,Q){
        ll a,b;cin >> a >> b;
        if(X.size() == 0){
            X.push_back(a);
            X.push_back(b);
            cout << "Yes" << "\n";
        }
        else{
            auto Ia = lower_bound(all(X), a);
            auto Ib = lower_bound(all(X), b);
            if(Ia==Ib){
                X.push_back(a);
                X.push_back(b);
                cout << "Yes" << "\n";
                sort(all(X));
            }
            else if(Ia-X.begin() == 0 && Ib-X.end() == 0){
                X.push_back(a);
                X.push_back(b);
                cout << "Yes" << "\n";
                sort(all(X));
            }
            else{
                cout << "No" << "\n";
            }
        }
    }
}