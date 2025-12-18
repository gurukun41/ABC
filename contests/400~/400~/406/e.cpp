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

const long long MAX = 998244353;

int digit_higher_bit(bitset<60> x, int k){  
    int rank = 0;
    ll ans = 1;
    bitset<60> n = x;
    while(n.any()){
      rank++;
      n >>= 1;
      ans *= rank;
      ans %= MAX;
    }
    
    if(rank < k){
        return 0;
    }
    
    int rank_k = rank-k;
    while(rank_k > 0){
        ans *= rank_k;
        ans %= MAX;
        rank_k --;
    }
    while(k > 0){
        ans /= k;
        k --;
    }
    return ans;
}

int main(){
    int T; cin >> T;
    ll N; int K;
    ll ans = 0;


    rep(i,0,T){
        cin >> N >> K;
        ans = 0;
        bitset<60> n(N);
        while(n.any()&&K>0){   
            ans += digit_higher_bit(n,K);
            ans %= MAX;
            n >>= 1;
            K--;
        }
        cout << ans << "\n";
    }

}