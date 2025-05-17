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
int main(){
    string S;cin >> S;

    map<char,bool> ch;
    ch['a'] = false;
    ch['b'] = false;
    ch['c'] = false;
    ch['d'] = false;
    ch['e'] = false;
    ch['f'] = false;
    ch['g'] = false;
    ch['h'] = false;
    ch['i'] = false;
    ch['j'] = false;
    ch['k'] = false;
    ch['l'] = false;
    ch['m'] = false;
    ch['n'] = false;
    ch['o'] = false;
    ch['p'] = false;
    ch['q'] = false;
    ch['r'] = false;
    ch['s'] = false;
    ch['t'] = false;
    ch['u'] = false;
    ch['v'] = false;
    ch['w'] = false;
    ch['x'] = false;
    ch['y'] = false;
    ch['z'] = false;

    for(char s: S){
        ch[s] = true;
    }
    for(auto ite = ch.begin(); ite != ch.end(); ite++){
        if(ite -> second){
            continue;
        }
        else{
            cout << ite -> first << "\n";
            return 0;
        }
    }
}