#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

/*
畳み込み

多項式積や「和がkになる組数」を高速に計算する。
長さNとMの配列から長さN+M-1の配列が返る。

998244353 mod なら convolution<mint>(a, b)
ll で正確に取りたいときは convolution_ll(a, b)
*/
void convolution_example() {
    vector<mint> a = {1, 2, 3};
    vector<mint> b = {4, 5};
    vector<mint> c = atcoder::convolution(a, b);
    // c = {4, 13, 22, 15}
    // c[k] = sum a[i] * b[k-i]

    vector<ll> x = {1, 2, 3};
    vector<ll> y = {4, 5};
    vector<ll> z = atcoder::convolution_ll(x, y);
    (void)c;
    (void)z;
}
