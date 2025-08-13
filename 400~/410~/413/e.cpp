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
#define rep(i,a,b) for(ll i = (a); i < (ll)(b); i++)  //for文の短縮
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

bool check(ll left,ll sep,vl &P){
    if(P[left]>P[left+sep/2]){
        return true;
    }
    else{
        return false;
    }
}

void swap(ll left,ll sep,vl &P){
    rep(i,0,sep/2){
        ll temp;
        temp = P[left+i];
        P[left+i] = P[left+sep/2+i];
        P[left+sep/2+i] = temp;
    }
    return;
}

int main(){
    int T;cin >> T;
    rep(x,0,T){
        ll N;cin >> N;
        ll num =  (1 << N);
        vl P(num);
        rep(i,0,num){
            cin >> P[i];
        }
        for(ll i=2;i<=num;i = (i<< 1)){
            for(ll j = 0; j < num; j+=i){
                if(check(j,i,P)){
                    swap(j,i,P);
                }
            }
        }
        rep(i,0,num){
            cout << P[i];
            if(i!=num-1){
                cout << " ";
            }
            else{
                cout << "\n";
            }
        }
    }
}