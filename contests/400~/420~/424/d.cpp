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

vvl v = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};

void search(vvl &M, ll num, ll i, ll j, ll &ans) {
    if(ans < num) return;
    ll nj = j, ni = i;
    if (j == M[0].size()-2) {
        if (i == M.size() - 2) {
            if (M[i][j] == '#' && M[i][j + 1] == '#' && M[i + 1][j] == '#' && M[i + 1][j + 1] == '#') {
                chmin(ans,num+1);
            }
            else{
                chmin(ans,num);
            }
            return;
        }
        else {
            nj = 0;
            ni++;
        }
    } 
    else {
        nj++;
    }
    if (num != 9 && M[i][j] == '#' && M[i][j + 1] == '#' && M[i + 1][j] == '#' && M[i + 1][j + 1] == '#') {
        rep(k, 0, 4) {
            M[i + v[k][0]][j + v[k][1]] = '.';
            search(M, num + 1, ni, nj, ans);
            M[i + v[k][0]][j + v[k][1]] = '#';
        }
    }
    else{
        search(M, num, ni, nj, ans);
    }
}

int main() {
    ll T;
    cin >> T;
    vl ans(T, (1 << 20));
    rep(_, 0, T) {
        ll H, W;
        cin >> H >> W;
        vector<string> S(H);
        rep(i, 0, H) cin >> S[i];
        vvl M(H, vl(W));
        rep(i, 0, H) {
            rep(j, 0, W) { M[i][j] = S[i][j]; }
        }
        search(M, 0, 0, 0, ans[_]);
    }
    rep(i, 0, T) { cout << ans[i] << "\n"; }
}