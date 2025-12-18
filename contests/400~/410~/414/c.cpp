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
    int A;
    ll N;
    cin >> A >> N;
    int count = 0;
    ll nc = N;
    while (nc > 0) {
        count++;
        nc /= 10;
    }
    vl rui10(count, 1);
    rep(i, 1, count) { rui10[i] = rui10[i - 1] * 10; }
    nc = N;
    int countA = 0;
    while (nc > 0) {
        countA++;
        nc /= A;
    }
    vl ruiA(countA, 1);
    rep(i, 1, countA) { ruiA[i] = ruiA[i - 1] * A; }

    ll ans = 0;
    auto dfs = [&](auto dfs, int i, ll sum, int c) -> void {
        if (i == (c - 1) / 2) {
            for (int ai = 0; ai < 10; ai++) {
                if (i == 0 && ai == 0) {
                    continue;
                }
                ll sumcp = sum;
                sumcp += ai * rui10[i];
                if (i != c - i - 1) {
                    sumcp += ai * rui10[c - i - 1];
                }
                if (sumcp > N) {
                    continue;
                }
                ll sumc = sumcp;

                string str = "";
                while (sumcp) {
                    str.push_back('0' + sumcp % A);
                    sumcp /= A;
                }
                reverse(all(str));

                bool isT = true;
                rep(ij, 0, (str.size() + 1) / 2) {
                    if (str[ij] != str[str.size() - ij-1]) {
                        isT = false;
                        break;
                    }
                }
                if (isT) {

                    ans += sumc;
                }
            }
            return;
        }
        for (int ai = 0; ai < 10; ai++) {
            if (i == 0 && ai == 0) {
                continue;
            }
            ll sumcp = sum;
            sumcp += ai * rui10[i];
            if (i != c - i - 1) {
                sumcp += ai * rui10[c - i - 1];
            }
            if (sumcp <= N) {
                dfs(dfs, i + 1, sumcp, c);
            }
        }

        return;
    };
    rep(i, 1, count + 1) { dfs(dfs, 0, 0, i); }

    cout << ans << "\n";
}