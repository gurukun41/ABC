#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;

// 問題に応じて使い分ける
using mint = atcoder::modint998244353;
// using mint = modint1000000007;
// using mint = modint; // 実行時にModが決まる場合(set_modが必要)

// --- 使用例 ---
void solve() {
    mint a = 10;
    mint b = 3;

    // 普通に計算するだけで自動でModが取られる
    mint ans = a + b;  // 13
    ans = a - 20;      // 負にならず、正の余りに補正される
    ans = a * b;       // 掛け算
    ans = a / b;       // 割り算 (モジュラ逆元を自動計算！)

    // 累乗もメンバ関数で一発
    mint p = ans.pow(100); 

    // 【重要】出力時は .val() をつける
    // cout << ans << endl; // コンパイルエラーになることがあります
    cout << ans.val() << endl;
}

// 組合せ
// --- nCr 高速計算ライブラリ ---
struct Combination {
    vector<mint> fact, ifact; // fact:階乗, ifact:階乗の逆元

    // コンストラクタ: nまでの階乗とその逆元を前計算する
    Combination(ll n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (ll i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        
        ifact[n] = fact[n].inv();
        
        for (ll i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }

    // nCk (組み合わせ)
    mint operator()(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }

    // nPk (順列)
    mint P(ll n, ll k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[n - k];
    }

    // nHk (重複組み合わせ)
    mint H(ll n, ll k) {
        if (n == 0 && k == 0) return 1;
        return (*this)(n + k - 1, k);
    }
};

int main() {
    ll N = 100000; // 使う可能性のある最大値
    
    // 1. 準備 (ここで O(N) かかる)
    Combination C(N); 

    // 2. 計算 (ここは O(1) で爆速)
    // 10個から3個選ぶ (10C3)
    mint ans1 = C(10, 3); 
    cout << ans1.val() << endl; // 120

    // 1000個から500個選ぶ (1000C500 mod 998244353)
    mint ans2 = C(1000, 500);
    cout << ans2.val() << endl;

    // nHk も計算可能
    // 3種類のアイスから重複を許して5個選ぶ
    mint ans3 = C.H(3, 5); 
    cout << ans3.val() << endl;
}
