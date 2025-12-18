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
vector<ll> enumerate_prime(ll n) {
  vector<bool> mark(n+1);
  vector<ll> ret;
  mark[1] = true;
  for (ll i=2; i<=n; i++){
    if (mark[i]){
      continue;
    }
    ret.push_back(i);
    for (ll j=2*i; j<=n; j+=i){
      mark[j] = true;
    }
  }
  return ret;
}
int main(){
    ll N;cin >> N;
    vl p = enumerate_prime(2e6);
    ll ans = 0;
    ll right = p.size();
    ll left = -1;
    while(right - left > 1){
        ll mid = (right+left)/2;
        if(pow(p[mid],8) <= N){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    ans += left +1;
    rep(i,0,(ll)p.size()){
        if(pow(p[i],2) > N){
            break;
        }
        else{
            ll right2 = p.size();
            ll left2 = i;
            while(right2 - left2 > 1){
                ll mid = (right2+left2)/2;
                if(pow(p[i],2)*pow(p[mid],2) <= N){
                    left2 = mid;
                }
                else{
                    right2 = mid;
                }
            }
            ans += left2  - i;
        }
    }
    cout << ans << "\n";
}