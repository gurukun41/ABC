#include <bits/stdc++.h>
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;

/*
最小費用流

指定した流量を流すときの最小コストを求める。
割当問題、重み付き二部マッチング、選択にコストがあるフローで使う。

mcf_graph<Cap, Cost> g(N);
g.add_edge(from, to, cap, cost);
auto [flow, cost] = g.flow(source, sink, flow_limit);

割当問題/最小コストマッチングで使う。
*/
void mincostflow_example(int n, int s, int t, ll limit, const vector<tuple<int, int, ll, ll>>& edges) {
    atcoder::mcf_graph<ll, ll> g(n);
    for (auto [u, v, cap, cost] : edges) g.add_edge(u, v, cap, cost);
    auto [flow, cost] = g.flow(s, t, limit);
    (void)flow;
    (void)cost;
}
