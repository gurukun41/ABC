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
bool check(ll i, ll j, vector<vector<char>> &S,vector<vector<char>> &T){
  rep(k,0,T.size()){
      rep(l,0,T.size()){
        if(S[i+k][j+l] != T[k][l]){
          return false;
        }
      }
      
  }
  return true;
}
int main(){
    int N,M; cin >> N >> M;
    vector<vector<char>> S(N,vector<char>(N)),T(M,vector<char>(M));
    rep(i,0,N){
      rep(j,0,N){
        cin >> S[i][j];
      }
    }
    rep(i,0,M){
      rep(j,0,M){
        cin >> T[i][j];
      }
    }

    rep(i,0,N-M+1){
      rep(j,0,N-M+1){
        if(S[i][j] == T[0][0]){
          if(check(i,j,S,T)){
            cout << i+1 << " "<<j+1 << "\n";
            return 0;
          }
        }
      }
    }
}