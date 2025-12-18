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
    vector<vector<pair<int, int>>> g(N);
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; // 1-indexedは0-indexedにしたほうが扱いやすい
        v--;
        g[u].emplace_back(v, w);
    }

    queue<pair<int, int>> q;
    vector<vector<int>> seen(N, vector<int>(1024,0));
    q.push({0,0});
    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        for(auto v:g[u.first]){
            int w =  u.second ^ v.second;
            if(seen[v.first][w]) continue;
            seen[v.first][w] = 1;
            q.push({v.first,w});
        }
    }

    rep(i,0,1024){
        if(seen[N-1][i]){
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}