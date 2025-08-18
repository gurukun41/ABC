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

const int SIGMA = 26;

struct AhoCorasick {
    vvl node;
    vl last;

    AhoCorasick() {
        node.emplace_back(vl(SIGMA, -1));
        last.emplace_back(0);
    }

    void add(string arr, ll ID){
        ll v = 0;
        for(char ch : arr){
            ll c = ch - 'a';
            if(node[v][c] == -1){
                node[v][c] = node.size();
                node.emplace_back(vl(SIGMA, -1));
                last.emplace_back(0);
            }
            v = node[v][c];
        }
        last[v] |= (1 << ID);
    }

    void build(){
        vl link(node.size(), 0);
        queue<ll> que;
        rep(i,0,SIGMA){
            if(node[0][i] == -1){
                node[0][i] = 0;
            }
            else{
                link[node[0][i]] = 0;
                que.push(node[0][i]);
            }
        }
        while(!que.empty()){
            ll v = que.front();
            que.pop();
            last[v] |= last[link[v]];
            rep(i,0,SIGMA){
                ll u = node[v][i];
                if(u == -1){
                    node[v][i] = node[link[v]][i];
                }
                else{
                    link[u] = node[link[v]][i];
                    que.push(u);
                }
            }
        }
    }
};

using mint = atcoder::modint998244353;

int main(){
    ll N,L;cin >> N >> L;
    AhoCorasick ac;
    rep(i,0,N){
        string S;cin >> S;
        ac.add(S,i);
    }

    ac.build();

    ll m = ac.node.size();
    vector<vector<mint>> dp((1<<N), vector<mint>(m, 0));
    dp[0][0] = 1;

    rep(len,0,L){
        vector<vector<mint>> ndp((1<<N), vector<mint>(m, 0));
        rep(bit,0,(1<<N)){
            rep(v,0,m){
                rep(i,0,SIGMA){
                    ll to = ac.node[v][i];
                    ll nbit = bit | ac.last[to];
                    ndp[nbit][to] += dp[bit][v];
                }
            }
        }
        dp = ndp;
    }
    mint ans = 0;
    rep(v,0,m){
        ans += dp[(1<<N) -1 ][v];
    }

    cout << ans.val() << "\n";
}