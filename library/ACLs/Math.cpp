#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using ll = long long;

/*
ACL Math

pow_mod(x, n, mod): x^n mod mod
inv_mod(x, mod): x の mod 逆元。gcd(x, mod) = 1 が必要
crt(r, m): x = r[i] (mod m[i]) を満たす x を求める
floor_sum(n, m, a, b): sum_{i=0}^{n-1} floor((a*i+b)/m)

自作するよりACLを使った方がバグりにくい。
*/
void acl_math_example() {
    ll p = atcoder::pow_mod(2, 10, 1000000007); // 1024
    ll inv = atcoder::inv_mod(3, 1000000007);

    auto [x, lcm] = atcoder::crt(vector<ll>{2, 3}, vector<ll>{5, 7});
    // 解なしの場合は {0, 0}
    // x は 0 <= x < lcm を満たす代表値

    ll s = atcoder::floor_sum(10, 7, 3, 4);
    (void)p;
    (void)inv;
    (void)x;
    (void)lcm;
    (void)s;
}
