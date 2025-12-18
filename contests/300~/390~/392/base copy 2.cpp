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
    int N;cin >> N;
    vector<int> K(N);
    vector<vector<int>> A(N,vector<int>(1));

    rep(i,0,N){
      int k;cin >>k;
      K[i] = k;
      A[i].resize(k);
      rep(j,0,k){
        cin >> A[i][j];
      }
      sort(A[i].begin(),A[i].end());
    }

    double ans = 0;
    rep(i,0,N-1){
      rep(j,i+1,N){
        double p = 0.0;
        for(auto value: A[i]){
          int l1=-1,r1=A[j].size();
          while(r1-l1>1){
            int m = (r1+l1)/2;
            if(A[j][m] >= value){
              r1=m;
            }
            else{
              l1=m;
            }
          }
          int l2=-1,r2=A[j].size();
          while(r2-l2>1){
            int m = (r2+l2)/2;
            if(A[j][m] > value){
              r2=m;
            }
            else{
              l2=m;
            }
          }
          p+=l2-r1+1;
          
        }
        p /= 1.0*K[i]*K[j];
        ans=max(p,ans);
      }
    }
    cout << fixed << setprecision(15);
    cout << ans << "\n";
}