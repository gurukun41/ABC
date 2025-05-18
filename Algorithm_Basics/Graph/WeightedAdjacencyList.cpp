#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;cin >> n >> m;

    //重み付き隣接リスト
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; // 1-indexedは0-indexedにしたほうが扱いやすい
        v--;
        g[u].emplace_back(v, w);
        // g[u].push_back(make_pair(v, w));
        // g[u].push_back(pair(v, w)); // これでもよい
        // g[u].push_back({v, w}); // これでもよい
        
        // 無向辺なら逆向きも追加
        g[v].emplace_back(u, w);
    }
}