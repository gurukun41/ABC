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
    ll N,S;cin >> N >> S;
    vl A(2*N);
    ll sum=0;
    rep(i,0,N){
      ll a; cin >> a;
      sum+=a;
      A[i] = sum;
    }
    rep(i,N,2*N){
      A[i] = sum + A[i-N];
    }
  S%=sum;
  set<ll> B;
  for(auto a: A){
    B.insert(a);
  }
  for(auto p: B){
    if(B.contains(p+S)){
      cout << "Yes" << "\n";
      return 0;
    }
  }
  cout << "No" << "\n";

}