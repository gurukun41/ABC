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
 ll next(ll &ans, ll i, vvl X, ll count, bool &can, vl leave,ll N){
    ll m = X[i].size();
    if(count == N || m == 0){
        return 0;
    }
    rep(k,0,m){
        ll j = X[i][X[i].size()-1];
        X[i].pop_back();
        if(j == 1){
            if(ans > count){
                ans = count;
            }
            can = true;
            return 0;
        }
        else if(leave[j]){
            continue;
        }
        count ++;
        leave[j] = 1;
        next(ans,j,X,count,can,leave,N);
    }
    return 0;
}
int main(){
    ll N,M;
    cin >> N >> M;
    vvl X(N+1,vl(0));
    rep(i,0,M){
        ll a,b;
        cin >> a >> b;
        X[a].push_back(b);
    }
    bool can = false;
    ll ans = N;
    vl leave(N+1,0);
    next(ans,1,X,1,can,leave,N);
    if(can){
        cout << ans;
    }
    else{
        cout << -1;
    }
}