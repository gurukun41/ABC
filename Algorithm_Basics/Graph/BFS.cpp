#include<bits/stdc++.h>
using namespace std;

//幅優先探索
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

    queue<int> q;
    vector<bool> seen(n, 0);
    q.push(0);
    seen[0] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:g[u]){
            if(seen[v]) continue;
            //動作
            seen[v] = 1;
            q.push(v);
        }
    }
}