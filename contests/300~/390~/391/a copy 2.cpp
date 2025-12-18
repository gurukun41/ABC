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
 ll N,Q; cin >> N >> Q;
 map<ll,ll> nest;
 map<ll,ll> unnest;
 map<ll,ll> bird;
 ll que;

 rep(i,0,Q){
  cin >> que;
  if(que == 2){
    cout << nest.size() << "\n";
  }
  else{
    ll p,h;cin >> p >> h;
    ll truep = p;
    if(bird.count(p)){
      truep = bird[p];    
    }
    bird[p] = h; 
    if(nest.count(truep)){
      nest[truep] --;
      if(nest[truep] == 0){
        nest.erase(truep);
      }
    }
    else{
      unnest[truep] = -1;
    }
    if(nest.count(h)){
      nest[h] ++;
    }
    else if(unnest.count(h)){
      unnest.erase(h);
    }
    else{
      nest[h] = 1;
    }
  }
 }   
}