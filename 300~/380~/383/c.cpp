#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;//long long型の一次元
using vvl = vector<vl>;//long long型の二次元配列
using vvvl = vector<vvl>;//long long型の三次元配列
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define bte(v) v.begin(), v.end()
template <typename T> 
T input(){
    T x;
    cin >> x;
    return x;
}
template <typename T> 
int input(ll &x){
    T y;
    cin >> y;
    x = y;
    return 0;
}
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main(){
    int H,W,D;cin >> H >>W >>D;
    vector<vector<char>> S(H,vector<char>(W));
    vector<pair<int,int>> ms(0);
    rep(i,0,H){
      rep(j,0,W){
        char s;cin >> s;
        S[i][j] = s;
        if(s == 'H'){
          pair<int,int> p=make_pair(i,j);
          ms.push_back(p);
        }
      }
    }
    vector<vector<int>> vis(H,vector<int>(W,D+1));
    vector<vector<int>> search;
    search = {{1,0},{0,1},{-1,0},{0,-1}};
    auto dfs = [&](auto dfs, int i, int j, int k) -> void{
      if (k==D){
        return;
      }
      for (auto p : search){
        int ni = i + p[0];
        int nj = j + p[1];
        if((0 <= ni && ni < H) && (0 <= nj && nj <W) && (S[ni][nj] != '#') && (vis[ni][nj] > k+1)){
          vis[ni][nj] = k+1;
          dfs(dfs, ni, nj, k+1);
        }
      }
      
    };


    for(auto p : ms){
      vis[p.first][p.second] = 0;
      dfs(dfs, p.first, p.second, 0);
    }
    int ans = 0;
    for(int i=0; i < H; i++){
      for(int j=0; j < W; j++){
        if(vis[i][j] <= D){
          ans ++;
        }
      }
    }
    cout << ans << "\n";
}