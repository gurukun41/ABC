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
    int N,M; cin >> N >>M;
    priority_queue<int, vector<int>, greater<int>> A;
    rep(i,0,M){
      int a;
      cin >> a;
      A.push(a);
    }

    int min=0;
    int num=0;
    queue<int> ans;
    rep(i,1,N+1){
      if(A.size() !=0){
            min = A.top();
      }
      if(i != min||min == N+1){
        ans.push(i);
        num ++;
      }
      else{
        while(min == i&&A.size()!=0){
          A.pop();
          if(A.size() !=0){
            min = A.top();
          }
          else{
            min = N+1;
          }
        }
      }
    }
    cout << num << "\n";
    int s = ans.size();
    rep(i,0,s){
      if(i==s-1){
        cout << ans.front();
      }
      else{
        cout << ans.front() << " ";
        ans.pop();
      }
    }
}