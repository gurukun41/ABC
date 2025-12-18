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
    ll H,W,D;cin >> H >>W >>D;
    vector<vector<char>> S(H,vector<char>(W));
    queue<pair<int, int>> que;
    vector<vector<int>> dist(H,vector<int>(W,-1));
    rep(i,0,H){
      rep(j,0,W){
        char s;cin >> s;
        S[i][j] = s;
        if(s == 'H'){
          pair<ll,ll> p=make_pair(i,j);
          dist[i][j] = 0;
          que.push(p);
        }
      }
    }
    vector<vector<int>> search;
    search = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!que.empty()){
      auto v = que.front();
      que.pop();
      for(auto p : search){
        ll i = v.first + p[0];
        ll j = v.second + p[1];
        if((0 <= i && i < H) && (0 <= j && j <W) && (S[i][j] != '#')){
          if(dist[i][j] != -1){
            continue;
          }
          dist[i][j] = dist[v.first][v.second] +1;
          pair<int,int> np=make_pair(i,j);
          que.push(np);
        }
      }
    }
    int ans =0;
    for(int i=0; i < H; i++){
      for(int j = 0; j<W; j++){
        if(dist[i][j] <= D && dist[i][j] != -1){
          ans++;
        }
      }
    }
    cout << ans << "\n";
}