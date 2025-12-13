#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using namespace std;

// --- 区間最小値 (RMQ) テンプレート ---
using S = ll;
S op(S a, S b) { return min(a, b); }
S e() { return 4e18; } // 単位元 (INF: これ以上大きな値はない数)

/* --- 区間和 (RSQ) テンプレート ---
using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; } // 単位元 (足しても変わらない数)
*/

/* --- SegTree 汎用テンプレート ---
using S = long long; // 扱うデータの型
S op(S a, S b) { return ...; } // 左右の子をマージする処理 (min, max, +, gcd)
S e() { return ...; } // 単位元 (minならINF, 和なら0, 積なら1)
*/

ll N,i,x,l,r;

int main(){
    // 宣言
    atcoder::segtree<S, op, e> seg(N); // または seg(vector<S> v);

    // 操作
    seg.set(i, x);    // i番目を x に更新
    seg.prod(l, r);   // [l, r) の最小値
}