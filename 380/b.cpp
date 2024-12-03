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
    string S;cin >> S;
    vector<ll> A(0);
    ll len = S.size();
    ll count = 0;
    rep(i,1,len){
      if(S[i] == '|'){
        A.push_back(count);
        count = 0;
      }
      else{
        count ++;
      }
    }
    ll size = A.size();
    rep(i,0,size){
      if(i != size-1){
        cout << A[i] << " ";
      }
      else{
        cout << A[i] << "\n";
      }
    }
}