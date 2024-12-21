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
    ll H,W,X,Y;cin >> H >> W >> X >> Y;X--;Y--;
    vector<vector<char>> S(H,vector<char>(W));
    rep(i,0,H){
      string s;cin >> s;
      rep(j,0,W){
        S[i][j] = s[j];
      }
    }
    string T;cin >> T;
    ll ans = 0;
    if(S[X][Y] == '@'){
      ans++;
      S[X][Y] = '.';
    }
    for(char t :T){
      if(t=='U' && X-1>=0 ){
        if(S[X-1][Y]=='.'){
          X--;
        }
        else if(S[X-1][Y]=='@'){
          S[X-1][Y] = '.';
          X--;
          ans++;
          
        }
      }
      else if(t=='D' && X+1<H ){
        if(S[X+1][Y]=='.'){
          X++;
        }
        else if(S[X+1][Y]=='@'){
          S[X+1][Y] = '.';
          X++;
          ans++;
          
        }
      }
      else if(t=='L' && Y-1>=0 ){
        if(S[X][Y-1]=='.'){
          Y--;
        }
        else if(S[X][Y-1]=='@'){
          S[X][Y-1] = '.';
          Y--;
          ans++;
          
        }
      }
      else if(t=='R' && Y+1<W ){
        if(S[X][Y+1]=='.'){
          Y++;
        }
        else if(S[X][Y+1]=='@'){
          S[X][Y+1] = '.';
          Y++;
          ans++;
          
        }
      }
    }
    cout << X+1 << " " << Y+1 << " " <<  ans << "\n";
}