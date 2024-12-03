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
    vector<double> X(N+1,0);
    vector<double> Y(N+1,0);
    double ans=0;
    for(ll i=0; i<N;i++){
        cin >> X[i+1] >> Y[i+1];
        ans += sqrt(pow(X[i+1]-X[i],2)+pow(Y[i+1]-Y[i],2));
    }
    ans += sqrt(pow(X[N]-X[0],2)+pow(Y[N]-Y[0],2));
    cout << fixed << setprecision(15) << ans;
}