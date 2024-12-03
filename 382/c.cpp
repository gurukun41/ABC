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
    ll N, M;cin >> N >> M;
    map<ll,ll> A;
    ll max = 0;
   rep(i,0,N){
    ll a ; cin >> a;
      if(A.count(a)){
        continue;
      }
      else{
        A[a] = i+1;
        if(a > max){
          max = a;
        }
      }
    }
   rep(i,0,M){
    ll b; cin >> b;
    ll ans = N+1;
    rep(j,1,b+1){
        if(A.count(j)){
          if(A[j] < ans){
            ans = A[j];
          }
        }
    }
    if(ans == N+1){
      cout << -1 << "\n";
    }
    else{
      cout << ans << "\n";
    }
  }
    
}