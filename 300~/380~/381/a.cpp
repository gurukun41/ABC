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
    ll N;cin >> N;if(N%2==0){cout << "No" << "\n";return 0;}
    string S; cin >> S;
    rep(i,0,N){
        if(i<(N+1)/2-1){
            if(S[i] != '1'){
                cout << "No" << "\n";
                return 0;
            }
        }
        else if(i==(N+1)/2-1){
            if(S[i]!='/'){
                cout << "No" << "\n";
                return 0;
            }
        }
        else{
            if(S[i]!='2'){
                cout << "No" << "\n";
                return 0;
            }
        }
    }
    cout << "Yes" << "\n";
}