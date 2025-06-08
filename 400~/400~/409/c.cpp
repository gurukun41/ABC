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

ll bit(vl &A, ll n, ll s){
    ll l1 = -1, r1 = n;
    while(r1-l1 > 1){
        ll mid = (r1+l1)/2;
        if(A[mid] <= s){
            l1 = mid;
        }
        else{
            r1 = mid;
        }
    }
    ll l2 = -1, r2 = n;
    while(r2-l2 > 1){
        ll mid = (r2+l2)/2;
        if(A[mid] >= s){
            r2 = mid;
        }
        else{
            l2 = mid;
        }
    }

    return l1 - r2 + 1;
}

int main(){
    int N,L; cin >> N >> L;
    if(L % 3 != 0){
        cout << 0 << "\n";
        return 0;
    }
    ll a;
    ll sum = 0;
    vl A(N);
    A[0] = 0;
    rep(i,0,N-1){
        cin >> a;
        sum += a;
        sum %= L;
        A[i+1] = sum;
    }
    sort(A.begin(), A.end());

    ll ans = 0;
    rep(i,0,L/3){
        ll temp = 1;
        temp *= bit(A,N,i);
        temp *= bit(A,N,i+L/3);
        temp *= bit(A,N,i+L/3*2);
        ans += temp;
    }

    cout << ans <<"\n";
}