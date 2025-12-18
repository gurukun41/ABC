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

int main(){
    int N, M;cin >> N >> M;
    //重み付き隣接リスト
    vector<vector<int>> g(M,vi(3));
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; // 1-indexedは0-indexedにしたほうが扱いやすい
        v--;
        g[i][0] = u;
        g[i][1] = v;
        g[i][2] = w;
    }

    queue<pair<int, int>> q;
    vector<int> seen(M, 0);
    rep(i,0,M){
        if(g[i][0] == 0){
            q.push({i,g[i][2]});
        }
    }
    ll min = INF;
    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        if(g[u.first][1] == N-1){
            if(u.second < min){
                min = u.second;
            }
        }

        rep(i,0,M){
            if(seen[i] == 2) continue;
            if(g[i][0] == g[u.first][1]){
                int a = u.second ^ g[i][2];
                seen[i] ++;
                q.push({i,a});
            }
        }
    }
    if(min == INF){
        cout << -1 << "\n";
    }
    else{
        cout << min << "\n";
    }
}