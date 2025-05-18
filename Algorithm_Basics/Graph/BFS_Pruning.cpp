#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;cin >> n >> m;

    //隣接リスト
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; // 1-indexedは0-indexedにしたほうが扱いやすい
        v--;
        g[u].push_back(v);
        
        // 無向辺なら逆向きも追加
        g[v].push_back(u);
    }

    queue<int> q;
    vector<bool> seen(n, 0);
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(seen[u]) continue;
        seen[u] = 1;
        for(int v:g[u]){
            if(seen[v]) continue; // 枝刈り
            q.push(v);
        }
    }
}