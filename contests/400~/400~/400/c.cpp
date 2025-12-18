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
bool chmax(T &a, const T& b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
//a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
bool chmin(T &a, const T& b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll inf = 1e9;
    ll N; cin >> N;
    ll num2 = 0, N2 = N;
    while(N2 > 0){
        N2/=2;
        num2 ++;
    }
    num2 --;
    ll a2 = 1;
    ll ans = 0;

    rep(i,0,num2){
        a2*=2;
        ll r = inf;
        ll l = -1;
        while(r-l>1){
            ll mid = (r+l)/2;
            if(mid*mid <= N/a2){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        
        ans += (l+1)/2 ;
    }
    cout << ans << "\n";
}