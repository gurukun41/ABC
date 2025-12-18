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
    vector<vector<char>> A(N+1,vector<char>(N+1));
    rep(i,1,N+1){
        rep(j,1,N+1){
            cin >> A[i][j];
        }
    }
    vector<vector<char>> B(N+1,vector<char>(N+1));
    rep(i,1,N/2+1){
        if(i%4==0){
            for(ll j=i; j<N+2-i; j++){
                B[i][j]=A[i][j];
                B[j][i]=A[j][i];
                B[N+1-i][j]=A[N+1-i][j];
                B[j][N+1-i]=A[j][N+1-i];
            }
        }
        else if(i%4==3){
            for(ll j=i; j<N+2-i; j++){
                B[N+1-j][i]=A[i][j];
                B[N+1-i][j]=A[j][i];
                B[N+1-j][N+1-i]=A[N+1-i][j];
                B[i][j]=A[j][N+1-i];
            }
        }
        else if(i%4==2){
            for(ll j=i; j<N+2-i; j++){
                B[N+1-i][N+1-j]=A[i][j];
            B[N+1-j][N+1-i]=A[j][i];
                B[i][N+1-j]=A[N+1-i][j];
                B[N+1-j][i]=A[j][N+1-i];
            }
        }
        else{
            for(ll j=i; j<N+2-i; j++){
                B[j][N+1-i]=A[i][j];
                B[i][N+1-j]=A[j][i];
                B[j][i]=A[N+1-i][j];
                B[N+1-i][N+1-j]=A[j][N+1-i];
            }
        }
    }
    rep(i,1,N+1){
        rep(j,1,N+1){
            cout << B[i][j];
        }
        cout << "\n";
    }
}