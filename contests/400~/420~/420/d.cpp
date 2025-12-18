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
    ll H, W;cin >> H >> W;
    vvvl A(2, vvl(H,vl(W)));
    pair<ll,ll> start, goal;
    rep(i,0,H){
        string S;cin >> S;
        rep(j,0,W){
            if(S[j] == 'S'){
                start = {i,j};
                A[0][i][j] = 0;
                A[1][i][j] = 0;
            }
            else if(S[j] == 'G'){
                goal = {i, j};
                A[0][i][j] = 3;
                A[1][i][j] = 3;
            }
            else if(S[j] == 'o'){
                A[0][i][j] = 0;
                A[1][i][j] = 1;                
            }
            else if(S[j] == 'x'){
                A[0][i][j] = 1;
                A[1][i][j] = 0;                
            }
            else if(S[j] == '?'){
                A[0][i][j] = 2;
                A[1][i][j] = 2;                
            }
            else if(S[j] == '.'){
                A[0][i][j] = 0;
                A[1][i][j] = 0;                
            }
            else if(S[j] == '#'){
                A[0][i][j] = 1;
                A[1][i][j] = 1;                
            }
        }
    }
    vvl vec = {{1,0},{0,1},{-1,0},{0,-1}};
    queue<vl> que;
    vl temp(4);
    temp[0] = 0;
    temp[1] = start.first;
    temp[2] = start.second;
    temp[3] = 0;
    que.push(temp);
    vector<vector<vector<bool>>> seen(2,vector<vector<bool>>(H, vector<bool>(W,false)));
    ll ans = -1;
    bool end = false;

    while(!(que.empty()) && !(end)){
        vl now = que.front();
        ll p = now[0], h = now[1], w = now[2], l = now[3];
        que.pop();
        if(seen[p][h][w]){
            continue;
        }
        else{
            seen[p][h][w] = true;
        }
        for(vl dv : vec){
            ll dh = h+dv[0], dw = w+dv[1];
            if(dh <0 || dh > H-1 || dw <0 || dw > W-1){
                continue;
            }
            if(A[p][dh][dw] == 2){
                vl nex = {!p,dh,dw,l+1};
                que.push(nex);
            }
            else if(A[p][dh][dw] == 0){
                vl nex = {p,dh,dw,l+1};
                que.push(nex);                
            }
            else if(A[p][dh][dw] == 3){
                ans = l+1;
                end = true;
                break;
            }
        }
    }

    cout << ans << "\n";
}