#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;                                  //long long型の一次元
using vvl = vector<vl>;                                 //long long型の二次元配列
using vvvl = vector<vvl>;                               //long long型の三次元配列
using vi = vector<int>;                                 //int型の一次元
using vvi = vector<vi>;                                 //int型の二次元配列
using vvvi = vector<vvi>;                               //int型の三次元配列
#define rep(i,a,b) for(int i = (a); i < (int)(b); i++)  //for文の短縮
#define all(v) v.begin(), v.end()                       //all(v)でvの始まりと終わりのイテレーター
//入力を受け取る
template <typename T> 
T input(){
    T x;
    cin >> x;
    return x;
}
//a,bのうち最大のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmax(T &a, const T& b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
//a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmin(T &a, const T& b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
// 無限大の値
//素数判定
bool is_prime(long long n) {
    if (n <= 1) {
      return false;
    }
    for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
}

const long long INF = 1LL << 60;
int main(){
    string S;cin >> S;
    int size = S.size();
    ll ans = size;
    int pre = 0;
    int now;
    
    rep(i,0,size){
        if(i == 0){
            pre = (int)(S[i]-'0');
            if(i == size-1){
                ans += pre;
            }
        }
        else{
            now = (int)(S[i]-'0');
            if(pre-now >= 0){
                ans += pre-now;
            }
            else{
                ans += 10 + (pre-now);
            }
            if(i == size-1){
                ans += now;
            }
            pre = now;
        }
    }
    cout << ans << "\n";
}