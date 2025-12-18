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
    ll N,K; cin >> N >> K;
    string S;cin >> S;
    bool pre1 = false;
    ll len = S.size();
    ll k=0;
    ll lk,rkm,rk;
    rep(i,0,len){
      if(S[i] == '1'){
        if(!pre1){
            k ++;
            pre1 = true;
            if(k==K){
              lk = i;
          }
        }
        if(i == len-1 && k == K){
          rk = i;
        }
      }
      else{
        if(pre1 && k == K){
            rk = i-1;
            break;
        }
        else if(pre1 && k == K-1){
          rkm = i-1;
        }
        pre1 = false;
      }
    }
    rep(i,0,len){
      if(rkm+1 <= i && i <= rkm+1 + rk -lk ){
        cout << '1' ;
      }
      else if(rkm + rk - lk +2 <= i && i <= rk){
        cout << '0';
      }
      else{
        cout << S[i] ;
      }
    }
    cout << "\n";
}