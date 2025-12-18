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
    int N,M;cin >> N >> M;
    vector<vector<int>> g(N,vector<int>(N,0));
    vector<pair<int,int>> s(N);
    rep(i,0,N){
        s[i] = make_pair(0,i);
    }
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--; // 0-indexed
        v--;
        g[u][v] = 1;
        g[v][u] = 1;
        s[u].first ++;
        s[v].first ++;
    }
    sort(s.begin(), s.end());
    ll ans = 0;
    while(true){
        if(s[0].first == 2 && s[N-1].first == 2){
            break;
        }
        
        ll tar = -1;
        for(ll i = N-1; i > 0; i--){
            if(s[i].first > 2){
                tar = i;
                break;
            }
        }
        if(tar != -1){
            for(ll i = tar-1; i > 0; i--){
                if(g[s[tar].second][s[i].second]){
                    g[s[tar].second][s[i].second] = 0;
                    g[s[i].second][s[tar].second] = 0;
                    s[i].first --;
                    s[tar].first --;
                    ans ++;
                    break;
                }
            }
        }
        else{
            rep(i,0,N){
                if(s[i].first < 2){
                    tar = i;
                    break;
                }
            }

            if(tar != -1){
                rep(i,tar+1,N){
                    if(!g[s[tar].second][s[i].second]){
                        g[s[tar].second][s[i].second] = 1;
                        g[s[i].second][s[tar].second] = 1;
                        s[i].first ++;
                        s[tar].first ++;
                        ans ++;
                        break;
                    }
                }
            }
        }
        sort(s.begin(), s.end());
    }
    cout << ans << "\n";
}