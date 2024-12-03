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
    ll N,M; cin >> N >> M;
    vl A(N);
    ll num = 0;
    auto dfs1 = [&](auto dfs1, ll i) -> void{
      if(i == N-1){
        rep(j,A[i-1]+10,M+1){
          A[i] = j;
          num ++;
        }
      }
      else{
        rep(j,A[i-1]+10,M-10*(N-i-1)+1){
          A[i] = j;
          dfs1(dfs1,i+1);
        }
      }
        
    };
    rep(j,1,M-10*(N-1)+1){
          A[0] = j;
          dfs1(dfs1,1);
    }
    cout << num << "\n";
    
    auto dfs = [&](auto dfs, ll i) -> void{
      if(i == N-1){
        rep(j,A[i-1]+10,M+1){
          A[i] = j;
          rep(k,0,N){
            if(k == N-1){
              std::cout << A[k] << "\n";
            }
            else{
              std::cout << A[k] << " ";
            }
          }
        }
      }
      else{
        rep(j,A[i-1]+10,M-10*(N-i-1)+1){
          A[i] = j;
          dfs(dfs,i+1);
        }
      }
        
    };
    rep(j,1,M-10*(N-1)+1){
          A[0] = j;
          dfs(dfs,1);
    }
}