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
    string S ; cin >> S;
    ll Q ; cin >> Q;
    ll len = S.size();
    ll K;
    rep(i,0,Q){
      cin >> K;
      K --;
      ll l = K%len;
      ll N = K/len ;
      char s = S[l];
      ll num =0;
      while(N != 0){
        if(N & 1 ){
            num ++;
        }
        N = N >> 1;
      }
      if(num%2==1){
        if(islower(s)){
          s -= 32;
            cout << s ;
        }
        else{
          s += 32;
          cout << s ;
        }
      }
      else{
        cout << s ;
      }
      if(i == Q-1){
        cout << "\n";
      }
      else{
        cout << " ";
      }
    }
}