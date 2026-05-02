#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace std;
using ll = long long;

/*
強連結成分分解

有向グラフで、互いに行き来できる頂点集合に分解する。
groups はトポロジカル順に返る。
同じ group 内の頂点は互いに行き来できる。
*/
void scc_example(int n, const vector<pair<int, int>>& edges) {
    atcoder::scc_graph g(n);
    for (auto [u, v] : edges) g.add_edge(u, v);

    vector<vector<int>> groups = g.scc();
    // groups[i] が1つの強連結成分
}
