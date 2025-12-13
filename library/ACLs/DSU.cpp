#include <atcoder/all>
using ll = long long;

ll N, u, v;

int main(){
    // 宣言: N頂点のDSUを作成 (0番目 〜 N-1番目)
    atcoder::dsu d(N);

    // 操作:
    d.merge(u, v);       // u と v を結合する (同じグループにする)
    if (d.same(u, v)) {  // u と v が同じグループか判定
        // 同じグループの場合の処理
    }

    // 情報取得:
    ll leader = d.leader(u); // u が属するグループの代表元(リーダー)を取得
    ll size = d.size(u);     // u が属するグループのサイズ(要素数)を取得
}