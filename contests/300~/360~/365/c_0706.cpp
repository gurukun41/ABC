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

ll check(ll x, vl &A){
    ll l = -1, r = A.size();
    while(r-l>1){
        ll m = (r+l)/2;
        if(A[m] > x){
            r = m;
        }
        else{
            l = m;
        }
    }
    return l;
}

int main(){
    ll N,M;cin >> N >> M;
    vl A(N);rep(i,0,N) cin >> A[i];
    sort(all(A));
    vl B(N);
    B[0] = A[0];
    rep(i,1,N) B[i] = B[i-1] + A[i];
    ll l = -1, r = A[N-1]+1;
    while(r-l>1){
        ll m = (r+l)/2;
        ll p = check(m,A);
        ll sum = 0;
        if(p == -1){
            sum = m*N;
        }
        else{
            sum = B[p] + m*(N-p-1);
        }
        if(sum > M){
            r = m;
        }
        else{
            l = m;
        }
    }
    ll x = l;
    if(x == A[N-1]){
        cout << "infinite" << "\n";
    }
    else{
        cout << x << "\n";
    }
}