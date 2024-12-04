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
    ll N;
    cin >> N;
    vl A(N),B(N-1);
    rep(i,0,N){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    rep(i,0,N-1){
        cin >> B[i];
    }
    sort(B.begin(),B.end());
    bool can = true;
    rep(i,0,N-1){
        if(A[i] > B[i]){
            can = false;
            cout << -1 ;
            return 0;
        }
    }
    if(can){
        rep(i,0,N){
        if(i != N-1 && A[N-1-i] > B[N-i-2]){
            cout << A[N-1-i];
            return 0;
        }
        else if(i == N-1){
            cout << A[0];
            return 0;
        }
        }
    }
}