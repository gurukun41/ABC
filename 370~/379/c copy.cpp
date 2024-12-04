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
    ll N,M; cin >> N >> M;
    ll ans = 0,suma = 0;
    vl X(M);rep(i,0,M){cin >> X[i];}
    map <ll,ll> A;rep(i,0,M){ll a;cin >> a;A[X[i]] = a;suma += a;}
    sort(X.begin(),X.end());
    if(X[0] != 1||suma != N){
        ans = -1 ;
    }
    else{
        rep(i,0,M){
            if(i == M-1){
                ll a = A[X[M-1-i]];
                if(a < N){
                    ans = -1;
                }
                else{
                    ans += N * (N-1) /2;
                }
            }
            else{
                ll a = A[X[M-1-i]],x=X[M-1-i];
                if(N-x < a){
                    ans += (N-x) * ( N - x + 1) /2;
                    N = x-1;
                }
                else{
                    ans += a * (2*N - 2*x + 1 - a)/2;
                    N -= a;
                }
            }
        }
    }
    cout << ans;
}