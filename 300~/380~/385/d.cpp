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
    ll N,M,X,Y;cin >> N >> M >> X >> Y;
    map<ll,vector<ll>> mx{};
    map<ll,vector<ll>> my{};
    rep(i,0,N){
      ll x,y;cin >> x >> y;
      if(mx.count(y)){
        mx[y].push_back(x);
      }
      else{
        mx[y] = {x};
      }
      if(my.count(x)){
        my[x].push_back(y);
      }
      else{
        my[x] = {y};
      }
    }
    for(auto& v:mx){
      sort(v.second.begin(), v.second.end());
    }
    for(auto& v:my){
      sort(v.second.begin(), v.second.end());
    }
    ll ans = 0;
    rep(i,0,M){
      char D;ll C;cin >> D >> C;
      if(D=='U'){
        if(my.count(X)){
          ll l1 = -1, r1 = my[X].size();
          while(r1-l1>1){
            ll m = (r1+l1)/2;
            if(my[X][m] >= Y){
              r1 = m;
            }
            else{
              l1 = m;
            }
          }
          ll l2 = -1, r2 = my[X].size();
          while(r2-l2>1){
            ll m = (r2+l2)/2;
            if(my[X][m] > Y+C){
              r2 = m;
            }
            else{
              l2 = m;
            }
          }
          rep(j,0,l2-r1+1){
            ll y = my[X][r1];

            erase(mx[y],X);
            my[X].erase(my[X].begin()+r1);
          }
          ans += l2-r1+1;
        }
        Y += C;
      }
      else if(D=='D'){
        if(my.count(X)){
          ll l1 = -1, r1 = my[X].size();
          while(r1-l1>1){
            ll m = (r1+l1)/2;
            if(my[X][m] >= Y-C){
              r1 = m;
            }
            else{
              l1 = m;
            }
          }
          ll l2 = -1, r2 = my[X].size();
          while(r2-l2>1){
            ll m = (r2+l2)/2;
            if(my[X][m] > Y){
              r2 = m;
            }
            else{
              l2 = m;
            }
          }
          rep(j,0,l2-r1+1){
            ll y = my[X][r1];
            erase(mx[y],X);
            my[X].erase(my[X].begin()+r1);
          }
          ans += l2-r1+1;
        }
        Y -= C;
      }
      else if(D=='L'){
        if(mx.count(Y)){
          ll l1 = -1, r1 = mx[Y].size();
          while(r1-l1>1){
            ll m = (r1+l1)/2;
            if(mx[Y][m] >= X-C){
              r1 = m;
            }
            else{
              l1 = m;
            }
          }
          ll l2 = -1, r2 = mx[Y].size();
          while(r2-l2>1){
            ll m = (r2+l2)/2;
            if(mx[Y][m] > X){
              r2 = m;
            }
            else{
              l2 = m;
            }
          }
          rep(j,0,l2-r1+1){
            ll x = mx[Y][r1];
            erase(my[x],Y);
            mx[Y].erase(mx[Y].begin()+r1);
          }
          ans += l2-r1+1;
        }
        X -= C;
      }
      else if(D=='R'){
        if(mx.count(Y)){
          ll l1 = -1, r1 = mx[Y].size();
          while(r1-l1>1){
            ll m = (r1+l1)/2;
            if(mx[Y][m] >= X){
              r1 = m;
            }
            else{
              l1 = m;
            }
          }
          ll l2 = -1, r2 = mx[Y].size();
          while(r2-l2>1){
            ll m = (r2+l2)/2;
            if(mx[Y][m] > X+C){
              r2 = m;
            }
            else{
              l2 = m;
            }
          }
          rep(j,0,l2-r1+1){
            ll x = mx[Y][r1];
            erase(my[x],Y);
            mx[Y].erase(mx[Y].begin()+r1);
          }
          ans += l2-r1+1;
        }
        X += C;
      }
    }
    cout << X << " " << Y << " " <<  ans << "\n";
}