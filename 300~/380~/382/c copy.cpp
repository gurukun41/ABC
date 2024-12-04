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
    vector<pair<ll,ll>> A(N);
   rep(i,0,N){
      ll a; cin >> a;
      pair <ll,ll> p(a,i+1);
      A[i] = p;
    }
    sort(A.begin(), A.end());
   vector<ll> B(M);
   rep(i,0,M){
      cin >> B[i];
    }
    rep(i,0,M){
      ll ok = -1;
      ll ng = N;
      while(abs(ok-ng) > 1){
        ll mid = (ok + ng)/2;
        if(A[mid].first <= B[i]){
          ok = mid;
        }
        else{
          ng = mid;
        }
      }
      if(ok == -1){
        cout << -1 << "\n";
      }
      else{
        cout << A[ok].second  << "\n";
      }
      
    }
}