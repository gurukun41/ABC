#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60; // 無限大を大きな値で定義

int main() {
    ll N, M;
    cin >> N >> M;
    
    // グラフを表現する隣接リスト
    vector<vector<ll>> adj(N + 1);
    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // BFSで閉路を検出する
    queue<pair<ll, ll>> q;  // {頂点, 距離}
    vector<ll> dist(N + 1, INF);  // 距離をINFで初期化
    vector<ll> parent(N + 1, -1); // 親を保持する配列（閉路の経路再構築用）

    dist[1] = 0;
    q.push({1, 0});

    ll min_cycle_length = INF;  // 最小の閉路長

    while (!q.empty()) {
        auto [v, d] = q.front();
        q.pop();
        
        for (ll u : adj[v]) {
            if (dist[u] == INF) {  // 未訪問の頂点
                dist[u] = d + 1;
                parent[u] = v;
                q.push({u, d + 1});
            } else if (u == 1) {  // 頂点1に戻ってきたら閉路が見つかる
                min_cycle_length = min(min_cycle_length, d + 1);
            }
        }
    }

    // 結果出力
    if (min_cycle_length == INF) {
        cout << -1 << endl;  // 閉路が見つからなかった場合
    } else {
        cout << min_cycle_length << endl;  // 最小の閉路長
    }

    return 0;
}
