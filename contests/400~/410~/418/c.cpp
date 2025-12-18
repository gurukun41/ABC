#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;                                     // long long型の一次元
using vvl = vector<vl>;                                    // long long型の二次元配列
using vvvl = vector<vvl>;                                  // long long型の三次元配列
using vi = vector<int>;                                    // int型の一次元
using vvi = vector<vi>;                                    // int型の二次元配列
using vvvi = vector<vvi>;                                  // int型の三次元配列
#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)  // for文の短縮
#define all(v) v.begin(), v.end()                          // all(v)でvの始まりと終わりのイテレーター

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

// 無限大の値
const long long INF = 1LL << 60;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vl A(N);
    vl S(N, 0);
    rep(i, 0, N) { cin >> A[i]; }
    vl ans(Q);
    sort(all(A));
    S[0] = A[0];
    rep(i, 1, N) { S[i] += S[i - 1] + A[i]; }
    rep(_, 0, Q) {
        ll b;
        cin >> b;
        if (b == 1) {
            ans[_] = 1;
            continue;
        }
        ll l = -1, r = N;
        while (r - l > 1) {
            ll m = (r + l) / 2;
            if (A[m] >= b) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r == N ) {
            ans[_] = -1;
        } 
        else if (r == 0) {
            ans[_] = (b - 1) * (N - r) + 1;
        } else {
            ans[_] = S[r - 1] + (b - 1) * (N - r) + 1;
        }
    }
    rep(i, 0, Q) { cout << ans[i] << "\n"; }
}