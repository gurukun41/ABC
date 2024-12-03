#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;//頭のstd省略もしcoutが曖昧だと指摘されたらstdをつける
using mint = atcoder::modint998244353;//なにこれ？
using ll = long long;//long long型の省略
#define rep(i,a,b) for(ll i = (a); i < (b); i++) //for文の省略
int main() {
    ll n,m;
    cin >> n >> m;
    vector <ll> A(n);//要素数を指定しないと動作しないことがある(なんで？)
    ll sumA=0 ;//Aの合計(代入の過程で足していく)
    rep(i,0,n){
        ll a;
        cin >> a;
        A[i] = a;
        sumA += a;
    }
    if (sumA <= m){
        cout << "infinite";//Aの合計がMを超えていなければ無限にできる
    }//超えていれば上限があるので以下の動作を行う
    else{
        ll target = 0;//最大の上限値よりも小さくなるAの個数
        sort(A.begin(),A.end());//昇順にする
        //（最大の上限値より大きくなるAになったときに実行を終了でき実行数が削減される）
        rep(i,0,n){
            if(A[i]*n <= m){
                target ++;
            }
            else{
                break;
            }
        }
        rep(i,0,target){
            m -= A[i];//target個目(A[target -1])までは全てその金額分払うので予算から差し引く
        }
        ll ans = m/(n - target);//残ったAの個数でさっき削った予算の残りを割った時の商が答え
        cout << ans;
    }
}