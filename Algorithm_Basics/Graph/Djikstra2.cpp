#include<bits/stdc++.h>
using namespace std;

using ll = long long;

//ダイクストラ法２
int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,ll>>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    ll myinf = 1e18;
    vector<ll> dist(n, myinf);
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        auto[cs, u] = pq.top();
        pq.pop();
        if(dist[u] < cs) continue;
        for(auto[v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }        
        }
    }
    
}