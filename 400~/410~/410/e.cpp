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

vector<vector<int>> dp(3009,vector<int>(3009));

int main(){
    int N,H,M;cin >> N >> H >> M;
    int ans = 0;
    rep(i,0,N+1) rep(j,0,M+1) dp[i][j] = -1;
    dp[0][M] =  H;
    rep(i,1,N+1){
        int A,B; cin >> A >> B;
        rep(j,0,M+1){
            if(j - B >= 0){
                if(dp[i-1][j] == -1) continue;
                ans = i;
                chmax(dp[i][j-B], dp[i-1][j]);
            }
            if(dp[i-1][j] - A >= 0){
                ans = i;
                chmax(dp[i][j], dp[i-1][j] - A);
            }
        }
    }

    cout << ans << "\n";
}