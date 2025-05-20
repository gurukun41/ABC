#include<bits/stdc++.h>
using namespace std;

//深さ優先探索
int main(){
    int n, m;cin >> n >> m;

    //隣接リスト
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; 
        v--;
        g[u].push_back(v);
        
        g[v].push_back(u);
    }

    vector<bool> seen(n, 0);
    auto dfs = [&](auto self, int u) ->void {
        seen[u] = 1;
        for(int v:g[u]){
            if(seen[v]) continue;
            self(self,v);
        }
    };
    dfs(dfs,0);
}