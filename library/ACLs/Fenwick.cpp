#include <atcoder/all>
using ll = long long;

ll N,i,x,l,r;

int main(){
    // 定義: サイズ N の配列（初期値 0）
    // 型は long long 推奨
    atcoder::fenwick_tree<ll> fw(N);

    // 操作例:
    fw.add(i, x);        // i番目 (0-indexed) に x を加算
    ll sum = fw.sum(l, r); // [l, r) の区間和を取得
}