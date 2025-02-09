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
  int N,W; cin >> N >> W;
  vector<priority_queue<int>>  A(W);
  vector<pair<int,int>> Ap(N);

  rep(i,0,N){
    int X,Y;cin >> X >> Y;
    X--;Y--;
    Y *= -1;
    A[X].push(Y);
    Ap[i] = make_pair(X,Y);
  }
  int msize = N;
  rep(i,0,W){
    int s = A[i].size();
    if(s < msize){
      msize = s;
    }
  }
  vector<int> lastpi(msize,0);
  vector<vector<int>> las(msize,vector<int>(W));
  rep(i,0,msize){
    rep(j,0,W){
      las[i][j] = A[j].top();
      A[j].pop();
      if(lastpi[i] > las[i][j]){
        lastpi[i] = las[i][j];
      }
    }
  }

  int Q;cin >> Q;
  rep(i,0,Q){
    int t,anum; cin >> t >> anum;
    anum --;
    int x=Ap[anum].first,y=Ap[anum].second;
    int r = msize,l=-1;
    while(r-l>1){
      int m = (r+l)/2;
      if(y >= las[m][x]){
        r=m;
      }
      else{
        l=m;
      }
    }
    if(r==msize){
      cout << "Yes" << "\n";
      continue;
    }
    else{
      if(lastpi[r] + t < 1){
        cout << "Yes" << "\n";
        continue;
      }
      else{
        cout << "No" << "\n";
        continue;
      } 
    }
  }
}