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
void search(ll i, ll l, ll num,const vl& H,ll& ans){
    if(i+l >= H.size()){
      if(num > ans){
        ans = num;
      }
      return ;
    }
    if(H[i] == H[i+l]){
      num ++;
      search(i+l,l,num,H,ans);
    }
    else{
      if(num > ans){
        ans = num;
      }
      return ;
    }
}
int main(){
    ll N; cin >> N;
    vl H(N);rep(i,0,N){cin >> H[i];}
    ll ans = 1;
    rep(i,0,N){
      rep(j,1,N-i){
        search(i,j,1,H,ans);
      }
    }
    cout << ans << "\n";
}