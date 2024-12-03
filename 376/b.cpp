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
    ll N,Q;
    cin >> N >> Q;
    vector<char> H(Q);
    vl T(Q);
    rep (i,0,Q){
        cin >> H[i] >> T[i];
    }
    ll L = 1, R = 2;
    ll ans = 0;
    rep(i,0,Q){
        if(L < T[i] && T[i] < R){
            if(H[i]== 'R'){
                ans += R - T[i];
                R = T[i];
            }
            else{
                ans += T[i] - L;
                L = T[i];
            }
        }
        else if(T[i]<L && L<R){
            if(H[i]== 'R'){
                ans += N - R + T[i];
                R = T[i];
            }
            else{
                ans += L -T[i];
                L = T[i];
            }            
        }
        else if(L < R && R< T[i]){
            if(H[i]== 'R'){
                ans += T[i] - R;
                R = T[i];
            }
            else{
                ans += N -T[i] + L;
                L = T[i];
            }            
        }
        else if(R < T[i] && T[i] < L){
            if(H[i]== 'R'){
                ans += T[i] - R;
                R = T[i];
            }
            else{
                ans += L - T[i];
                L = T[i];
            }            
        }
        else if(T[i] < R&&R < L){
            if(H[i]== 'R'){
                ans += R - T[i];
                R = T[i];
            }
            else{
                ans += N - L + T[i];
                L = T[i];
            }            
        }
        else if(R < L && L < T[i]){
            if(H[i]== 'R'){
                ans += N - T[i] + R;
                R = T[i];
            }
            else{
                ans += T[i] - L;
                L = T[i];
            }            
        }
    }
    cout << ans;
}