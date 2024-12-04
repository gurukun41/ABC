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
  ll N, M;
  cin >> N >> M;

  vector<pair<ll,ll>> canget;
  ll ans =N*N;
  rep(i,0,M){
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    pair<ll,ll> p1(a,b);
    if(find(canget.begin(),canget.end(),p1) == canget.end()){
      canget.push_back(p1);
      ans --;
    }
    if(a>1){
      if(b>0){
        pair<ll,ll> p2(a-2,b-1);
        if(find(canget.begin(),canget.end(),p2) == canget.end()){
          canget.push_back(p2);
          ans--;
        }
      }
      if(b<N-1){
        pair<ll,ll> p3(a-2,b+1);
        if(find(canget.begin(),canget.end(),p3) == canget.end()){
          canget.push_back(p3);
          ans--;
        }
      }
    }
    if(a>0){
      if(b>1){
        pair<ll,ll> p4(a-1,b-2);
        if(find(canget.begin(),canget.end(),p4) == canget.end()){
          canget.push_back(p4);
          ans--;
        }
      }
      if(b<N-2){
        pair<ll,ll> p5(a-1,b+2);
        if(find(canget.begin(),canget.end(),p5) == canget.end()){
          canget.push_back(p5);
          ans--;
        }
      }
    }
    if(a<N-1){
      if(b>1){
        pair<ll,ll> p6(a+1,b-2);
        if(find(canget.begin(),canget.end(),p6) == canget.end()){
          canget.push_back(p6);
          ans--;
        }
      }
      if(b<N-2){
        pair<ll,ll> p7(a+1,b+2);
        if(find(canget.begin(),canget.end(),p7) == canget.end()){
          canget.push_back(p7);
          ans--;
        }
      }
    }
    if(a<N-2){
      if(b>0){
        pair<ll,ll> p8(a+2,b-1);
        if(find(canget.begin(),canget.end(),p8) == canget.end()){
          canget.push_back(p8);
          ans--;
        }
      }
      if(b<N-1){
        pair<ll,ll> p9(a+2,b+1);
        if(find(canget.begin(),canget.end(),p9) == canget.end()){
          canget.push_back(p9);
          ans--;
        }
      }
    }
  }
  cout << ans << "\n";
}