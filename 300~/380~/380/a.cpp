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
    string N ; cin >> N;
    ll num1=0,num2=0,num3=0;
    rep(i,0,6){
        if(N[i] == '1'){
            num1++;
        }
        else if(N[i] == '2'){
            num2++;
        }
        else if(N[i] == '3'){
            num3++;
        }
    }
    if(num1==1 && num2==2 && num3==3){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
}