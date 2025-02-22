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
int inf = 1000000010;
int main(){
    int n;cin >> n;
    vector<vector<char>> c(n, vector<char>(n));
    rep(i,0,n) rep(j,0,n) cin >> c[i][j];
    vector<vector<int>> a(n, vector<int>(n,inf));
    queue<pair<int,int>> que;
    rep(i,0,n){
        que.push({i,i});
        a[i][i] = 0;
    }
    rep(i,0,n) rep(j,0,n){
        if(i==j || c[i][j]=='-') continue;
        que.push({i,j});
        a[i][j] = 1;
    }
    while(!que.empty()){
        auto q = que.front();que.pop();
        int i = q.first, j = q.second;
        rep(k, 0, n) rep(l, 0, n){
            if(c[k][l] != '-' && c[j][l] != '-' && c[k][i] == c[j][l] && a[k][l] == inf){
                a[k][l] = a[i][j] + 2;
                que.push({k, l});
            }
        }
    }
    rep(i, 0, n) rep(j,0,n){
        cout << (a[i][j] == inf ? -1 : a[i][j]) << " \n"[j == n-1];
    }
}