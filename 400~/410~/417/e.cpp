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

int main(){
    ll T;cin >> T;
    rep(x,0,T){
        ll N,M,X,Y;cin >> N >> M >> X >> Y;
        vector<vector<int>> g(N+1);
        for(int i = 0; i < M; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);

            g[v].push_back(u);
        }
        rep(i,0,N+1){
            sort(all(g[i]));
        }
        vector<bool> seen(N+1,0);
        vl out(N,-1);
        ll outs = 0;
        bool end = false;
        auto dfs = [&](auto dfs, int pos, vl ans) -> void {
            if(end){
                return;
            }
            seen[pos] = true;
            int size = ans.size();
            rep(i,0,g[pos].size()){
                int next = g[pos][i];
                if(end){
                    return;
                }
                if(next == Y){
                    if(ans.size() == size){
                        ans.push_back(next);
                    }
                    else{
                        ans[size] = next;
                    }
                    rep(j,0,size+1){
                        out[j] = ans[j];
                    }
                    outs = size+1;
                    end = true;
                    return;
                }
                if (!seen[next]) {
                    if(ans.size() == size){
                        ans.push_back(next);
                    }
                    else{
                        ans[size] = next;
                    }
                    dfs(dfs,next,ans);
                }
            }
        };
        vl answer(1,X);
        dfs(dfs,X,answer);

        rep(i,0,outs){
            cout << out[i] << " ";
        }
        cout << "\n";
    }
}