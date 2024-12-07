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
    ll H,W,D;cin >> H >>W >>D;
    vector<pair<ll,ll>> ms(0);
    rep(i,0,H){
      rep(j,0,W){
        char s;cin >> s;
        if(s == '.'){
          pair<ll,ll> p=make_pair(i,j);
          ms.push_back(p);
        }
      }
    }
    ll ans =0;

    for(auto p1 :ms){
      for(auto p2 :ms){
        if(p1 == p2){
          continue;
        }
        ll num = 0;
        for(auto p :ms){
          ll d1 = abs(p.first-p1.first) + abs(p.second-p1.second);
          ll d2 = abs(p.first-p2.first) + abs(p.second-p2.second);
          if(d1 <= D || d2 <= D){
            num ++;
          }
        }
        if (num > ans){
          ans = num;
        }
      }
    }
    cout << ans << "\n";
}