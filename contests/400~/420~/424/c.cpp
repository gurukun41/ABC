#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;                                   // long long型の一次元
using vvl = vector<vl>;                                  // long long型の二次元配列
using vvvl = vector<vvl>;                                // long long型の三次元配列
using vi = vector<int>;                                  // int型の一次元
using vvi = vector<vi>;                                  // int型の二次元配列
using vvvi = vector<vvi>;                                // int型の三次元配列
#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)  // for文の短縮
#define all(v) v.begin(), v.end()                        // all(v)でvの始まりと終わりのイテレーター

// 入力を受け取る
template <typename T>
T input() {
    T x;
    cin >> x;
    return x;
}

// a,bのうち最大のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// 素数判定
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


int main() {
    ll N;cin >> N;
    vl A(N+1),B(N+1);
    vl Have(N+1,0);
    queue<ll> q;
    vvl C(N+1);
    ll ans=0;
    rep(i,1,N+1){
        cin >> A[i] >> B[i];
        if(A[i] == 0){
            if(Have[i]){
                continue;
            }
            Have[i] = 1;
            q.push(i);
            ans++;
        }
        else{
            C[A[i]].push_back(i);
            C[B[i]].push_back(i);
        }
    }
    while(!q.empty()){
        ll nex = q.front();
        q.pop();
        for(ll x: C[nex]){
            if(Have[x]){
                continue;
            }
            Have[x] = 1;
            q.push(x);
            ans++;
        }
    }
    cout << ans << "\n";
}