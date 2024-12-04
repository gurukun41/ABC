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
ll ans=0;
ll H,W,K;
void search(vector<vector<char>> &S,ll i, ll j, ll num,vector<vector<ll>> &seen){
    seen[i][j] = 1;
    if(num == K){
        ans++;
        seen[i][j] = 0;
        return ;
    }
    else{
        num ++;
        if(S[i+1][j] == '.'&& !seen[i+1][j]){
            search(S,i+1,j,num,seen);              
        }
        if(S[i-1][j]=='.'&& !seen[i-1][j]){
            search(S,i-1,j,num,seen);
        }
        if(S[i][j+1]=='.'&& !seen[i][j+1]){
            search(S,i,j+1,num,seen);
        }
        if(S[i][j-1]=='.'&&!seen[i][j-1]){
            search(S,i,j-1,num,seen);
        }
    }
    seen[i][j]=0;
    return;
}
int main(){
    cin >> H >> W >> K;
    vector<vector<ll>> seen(H+2,vector<ll>(W+2,0));
    vector<vector<char>> S(H+2,vector<char>(W+2));rep(i,1,H+1){rep(j,1,W+1){cin >> S[i][j];}}
    rep(i,0,H+2){S[i][0] = '#';S[i][W+1] = '#';}
    rep(i,0,W+2){S[0][i] = '#';S[H+1][i]='#';}
    rep(i,1,H+1){
        rep(j,1,W+1){
            if(S[i][j] == '.'){
                search(S,i,j,0,seen);
            }
        }
    }
    cout << ans << "\n";
}