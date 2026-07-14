#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

// ===== Lazy SegTree: 区間更新 + 区間取得 =====
// 0-indexed / [l, r) / O(log N)
// 使うときは S, F, op, e, mapping, composition, id を1組だけ残す。
// composition(f, g): 古い操作 g の後に、新しい操作 f をする。

// --- RAQ + RMQ: 区間加算 + 区間最小値 ---
using S = ll;
using F = ll;
S op(S a, S b) { return min(a, b); }
S e() { return (1LL << 60); }
S mapping(F f, S x) { return x + f; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

/* --- RAQ + RSQ: 区間加算 + 区間和 ---
struct S {
    ll sum;
    int size;
};
using F = ll;
S op(S a, S b) { return {a.sum + b.sum, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) { return {x.sum + f * x.size, x.size}; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

vector<S> a(N);
for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    a[i] = {x, 1};
}
atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

seg.apply(l, r, x);             // [l, r) に x を加算
ll ans = seg.prod(l, r).sum;     // [l, r) の和
*/

/* --- RUQ + RMQ: 区間代入 + 区間最小値 ---
using S = ll;
struct F {
    ll x;
    bool set;
};
S op(S a, S b) { return min(a, b); }
S e() { return (1LL << 60); }
S mapping(F f, S x) { return f.set ? f.x : x; }
F composition(F f, F g) { return f.set ? f : g; }
F id() { return {0, false}; }

vector<S> a(N);
for (int i = 0; i < N; i++) cin >> a[i];
atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

seg.apply(l, r, {x, true});  // [l, r) を x に代入
ll ans = seg.prod(l, r);     // [l, r) の最小値
*/

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<S> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    // atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);

    while (Q--) {
        int type;
        cin >> type;

        if (type == 0) {
            int l, r;
            F x;
            cin >> l >> r >> x;
            seg.apply(l, r, x); // [l, r) に x を加算
        }

        if (type == 1) {
            int i;
            S x;
            cin >> i >> x;
            seg.set(i, x); // a[i] = x
        }

        if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r) << '\n'; // [l, r) の最小値
        }
    }
}
