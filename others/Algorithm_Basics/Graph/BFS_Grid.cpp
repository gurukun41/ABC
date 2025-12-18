#include<bits/stdc++.h>
using namespace std;

//幅優先探索 グリッド
int main(){
    int h, w;
    cin >> h >> w;

    int start_h, start_w;
    cin >> start_h >> start_w;

    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    vector<vector<int>> seen(h,vector<int>(w,0));
    queue<pair<int,int>> q;
    q.push({start_h,start_w});
    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        if(seen[x][y]) continue;
        seen[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(seen[nx][ny]) continue;
            q.push({nx, ny});
        }
    }
}