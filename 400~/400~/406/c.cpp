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
    bool first = false; 
    bool second = false; 
    bool last = false; 
    int N; cin >> N;

    int pre;
    queue<int> S;
    rep(i,0,N){
        int P;cin >> P;
        if(i==0){
            pre = P;
        }
        else{
            if(first){
                if(pre > P){
                    S.push(i-1);
                    first = false;
                    second = true;
                }
            }
            else if(second){
                if(pre < P){
                    S.push(i-1);
                    second = false;
                    last = true;
                }
            }
            else if(last){
                if(pre > P){
                    S.push(i-1);
                    last = false;
                    second = true;
                }
            }
            else{
                //全部偽
                if(pre < P){
                    S.push(i-1);
                    first = true;
                }
                else if(i == N-1){
                    cout << 0 << "\n";
                    return 0;
                }
            }
            pre = P;
        }
    }


    ll ans = 0;
    if(S.size() == 0 || S.size() == 1){
        cout << ans << "\n";
        return 0;
    }
    ll S1,S2,S3,S4;
    S1 = S.front();S.pop();
    S2 = S.front();S.pop();
    while(!S.empty()){
        S3 = S.front();S.pop();
        if(S.empty()){
            S4 = N-1;
        }
        else{
            S4 = S.front();S.pop(); 
        }

        ans += (S2-S1)*(S4-S3);

        S1 = S3;
        S2 = S4;
    }

    cout << ans << "\n";

}