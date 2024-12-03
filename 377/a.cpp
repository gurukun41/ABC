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
    string S;
    cin >> S;
    bool a=false;
    bool b=false;
    bool c=false;
    rep(i,0,3){
        char s = S[i];
        if(s == 'A'){
            a = true;
        }
        else if(s == 'B'){
            b = true;
        }
        else if(s== 'C'){
            c = true;
        }
    }
    if(a&&b&&c){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
}