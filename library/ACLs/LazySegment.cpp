#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

// --- 区間加算・区間最小値 (RAQ + RMQ) ---
using S = ll;
using F = ll;

const S INF = 4e18;

S op(S a, S b) { return min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; } // 遅延(f)を要素(x)に反映
F composition(F f, F g) { return f + g; } // 遅延(f)を既存の遅延(g)に合成
F id() { return 0; } // 何もしない遅延タグ


/* --- Lazy SegTree 完全テンプレート ---
// S: 配列の要素の型 (例: struct Node { ll val; int size; }; )
// F: 操作(遅延)の型 (例: ll add_val;)
using S = long long;
using F = long long;

// 1. 要素同士のマージ (区間取得の結果)
S op(S a, S b) { return min(a, b); }

// 2. 要素の単位元 (初期値や範囲外の値)
S e() { return 4e18; }

// 3. 要素(x)に操作(f)を適用する関数
// ※ 区間和の区間加算なら、x.val += f * x.size になる点に注意
S mapping(F f, S x) { return x + f; }

// 4. 操作(g)に対して、さらに新しい操作(f)を合成する関数 (順序: g -> f)
// 例: xにgを足して、さらにfを足す -> 結果として f+g を足す
F composition(F f, F g) { return f + g; }

// 5. 操作の単位元 (何もしない操作)
F id() { return 0; }
*/

ll N,i,x,l,r;

int main(){
    // 宣言
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);

    // 操作
    seg.apply(l, r, x); // [l, r) に x を加算
    seg.prod(l, r);     // [l, r) の最小値を取得
}