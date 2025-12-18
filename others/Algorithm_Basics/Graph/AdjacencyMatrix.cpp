#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;cin >> n >> m;

    //隣接行列
    int myinf = 1e9; // 入力に含まれないような適当な値で初期化
    vector<vector<int>> g(n, vector<int>(n, myinf));
    for(int i = 0; i < m; i++){
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        g[u][v] = x;

        // 無向辺なら逆向きも追加
        g[v][u] = x;
    }
}