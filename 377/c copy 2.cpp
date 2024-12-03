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
  ll N, M;
  cin >> N >> M;
  vector<vector<bool>> canget(N,vector<bool>(N,false));
  ll ans =N*N;
  rep(i,0,M){
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    if(!canget[a][b]){
      canget[a][b] = true;
      ans --;
    }
    if(a>1){
      if(b>0){
        if(!canget[a-2][b-1]){
          canget[a-2][b-1] = true;
          ans--;
        }
      }
      if(b<N-1){
        if(!canget[a-2][b+1]){
          canget[a-2][b+1] = true;
          ans--;
        }
      }
    }
    if(a>0){
      if(b>1){
        if(!canget[a-1][b-2]){
          canget[a-1][b-2] = true;
          ans--;
        }
      }
      if(b<N-2){
        if(!canget[a-1][b+2]){
          canget[a-1][b+2] = true;
          ans--;
        }
      }
    }
    if(a<N-1){
      if(b>1){
        if(!canget[a+1][b-2]){
          canget[a+1][b-2] = true;
          ans--;
        }
      }
      if(b<N-2){
        if(!canget[a+1][b+2]){
          canget[a+1][b+2] = true;
          ans--;
        }
      }
    }
    if(a<N-2){
      if(b>0){
        if(!canget[a+2][b-1]){
          canget[a+2][b-1] = true;
          ans--;
        }
      }
      if(b<N-1){
        if(!canget[a+2][b+1]){
          canget[a+2][b+1] = true;
          ans--;
        }
      }
    }
  }
  cout << ans << "\n";
}