#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace std;
using ll = long long;

/*
最大流

sourceからsinkへ流せる最大量を求める。
容量制約、二部マッチング、辺/頂点を選ぶ問題で使う。

mf_graph<Cap> g(N);
g.add_edge(from, to, cap);
Cap ans = g.flow(source, sink);

二部マッチングにも使う:
source -> 左側, 左側 -> 右側, 右側 -> sink の容量をすべて1にする。
*/
void maxflow_example(int n, int s, int t, const vector<tuple<int, int, ll>>& edges) {
    atcoder::mf_graph<ll> g(n);
    for (auto [u, v, cap] : edges) g.add_edge(u, v, cap);
    ll ans = g.flow(s, t);
    // g.edges() で各辺の流量も見られる
    (void)ans;
}
