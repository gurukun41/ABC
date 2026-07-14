#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// ===== SegTree: 1点更新 + 区間取得 =====
// 0-indexed / [l, r) / O(log N)
// 使うときは S, op, e を1組だけ残す。

// --- RMQ: 区間最小値 ---
using S = ll;
S op(S a, S b) { return min(a, b); }
S e() { return (1LL << 60); }

/* --- RMaxQ: 区間最大値 ---
using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return -(1LL << 60); }
*/

/* --- RSQ: 区間和 ---
using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }
*/

/* --- GCD ---
using S = ll;
S op(S a, S b) { return gcd(a, b); }
S e() { return 0; }
*/

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<S> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    atcoder::segtree<S, op, e> seg(a);
    // atcoder::segtree<S, op, e> seg(N); // 全要素 e() で初期化

    while (Q--) {
        int type;
        cin >> type;

        if (type == 0) {
            int i;
            S x;
            cin >> i >> x;
            seg.set(i, x); // a[i] = x
        }

        if (type == 1) {
            int i;
            S x;
            cin >> i >> x;
            seg.set(i, seg.get(i) + x); // a[i] += x
        }

        if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r) << '\n'; // [l, r)
        }
    }
}
