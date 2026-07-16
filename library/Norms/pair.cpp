#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

int main() {
    pl p = {10, 20};

    // コピー: x, yを変更してもpは変わらない
    auto [x, y] = p;
    x++;
    y--;

    // 参照: a, bを変更するとpも変わる
    auto &[a, b] = p;
    a++;
    b--;

    // const参照: コピーせず、読み取りだけ行う
    const auto &[u, v] = p;
    cout << u << ' ' << v << '\n';

    vpl edges = {{1, 2}, {3, 4}};

    // vector<pair>をコピーせずに走査
    for (const auto &[from, to] : edges) {
        cout << from << ' ' << to << '\n';
    }

    // 要素を書き換える場合は参照にする
    for (auto &[from, to] : edges) {
        from--;
        to--;
    }

    // priority_queue::top()はpop前にコピーする
    priority_queue<pl, vpl, greater<pl>> pq;
    pq.push({5, 6});
    auto [dist, vertex] = pq.top();
    pq.pop();
    cout << dist << ' ' << vertex << '\n';

    // pairの比較はfirst、同じならsecondの辞書順
    sort(edges.begin(), edges.end());
}
