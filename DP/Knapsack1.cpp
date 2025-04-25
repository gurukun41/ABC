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
const long long INF = 1LL << 60;
ll w[110];
ll v[110];
//DP　テーブル
ll dp[110][100100];

int main(){
    ll N,W; cin >> N >> W;
    rep(i,0,N) cin >> w[i] >> v[i];
    rep(i,0,110) rep(j,0,100100) dp[i][j] = INF;
    dp[0][0] = 0;
    ll ans = 0;
    rep(i,0,N){
        rep(j,0,100100){
            if(dp[i][j] == INF||j+v[i]>=100100) continue;
            chmin(dp[i+1][j+v[i]], dp[i][j] + w[i]);
            if(dp[i+1][j+v[i]] <= W){
                chmax(ans, j+v[i]);
            }
            chmin(dp[i+1][j], dp[i][j]);
            
              
        }
    }

    cout << ans << "\n";
}