#include<bits/stdc++.h>
using namespace std;

//深さ優先探索　枝刈り
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

    stack<int> s;
    vector<bool> seen(n, 0);
    s.push(0);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(seen[u]) continue;
        seen[u] = 1;
        for(int v:g[u]){
            if(seen[v]) continue; // 枝刈り
            s.push(v);
        }
    }
}