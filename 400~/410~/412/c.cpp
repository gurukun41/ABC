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

ll check(ll tar, vl &s){
    ll l = -1, r = s.size();
    while(r-l > 1){
        ll m = (r+l)/2;
        if(s[m] > tar){
            r = m;
        }
        else {
            l = m;
        }
    }

    return l;
}

int main(){
    ll T;cin >> T;
    rep(i,0,T){
        ll N;cin >> N;
        vl s(N-2);
        ll start,end;
        cin >> start;
        rep(j,0,N-2) cin >> s[j];
        cin >> end;
        sort(s.begin(), s.end());
        ll tar = start;
        ll ans = -1;
        ll temp = 0;  
        while(true){
            if(tar*2 >= end){
                ans = temp;
                break;
            } 
            ll p = check(tar*2, s);
            if(p == -1){
                // 不可能
                break;
            }
            if(s[p] <= tar){
                // 不可能
                break;
            }
            else{
                temp ++;
                tar = s[p];
            }
        }
        if(ans != -1){
            ans += 2;
        }
        cout << ans << "\n";
    }
}