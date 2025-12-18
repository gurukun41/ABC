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

// 無限大の値
const long long INF = 1LL << 60;

int main(){
    ll H,W;cin >> H >> W;
    vvl A(H,vl(W));rep(i,0,H) rep(j,0,W) cin >> A[i][j];
    vl P(H+W-1);rep(i,0,H+W-1) cin >> P[i];
    vector<vector<pair<ll,ll>>> dp(H,vector<pair<ll,ll>>(W,{-INF,0}));
    dp[0][0] = {A[0][0],0};
    if(dp[0][0].first-P[0] < 0){
        dp[0][0].second = -(dp[0][0].first-P[0]);
        dp[0][0].first = P[0];
    }
    rep(i,1,H+W){
        rep(j,0,i+1){
            if(i-j>=H||j>=W){
                continue;
            }
            if(i-j>0){
                if(chmax(dp[i-j][j].first,dp[i-j-1][j].first-P[i-1]+A[i-j][j])){
                    dp[i-j][j].second = dp[i-j-1][j].second;
                } 
            }
            if(j>0){
                if(chmax(dp[i-j][j].first,dp[i-j][j-1].first-P[i-1]+A[i-j][j])){
                    dp[i-j][j].second = dp[i-j][j-1].second;
                }
            }
            if(dp[i-j][j].first - P[i] < 0){
                dp[i-j][j].second += -(dp[i-j][j].first-P[i]);
                dp[i-j][j].first = P[i];
            }
            
        }
    }

    cout << dp[H-1][W-1].second << "\n";

}