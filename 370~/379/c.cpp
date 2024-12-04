#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
int main(){
    int N,M; cin >> N >> M; //N,Mの受け取り
    int ans = 0; // 答えをこれに記憶させる
    vector<int> X(M);for(int i=0;i<M;i++){cin >> X[i];} //Xの受け取り
    map <int,int> A;for(int i=0;i<M;i++){int a;cin >> a;A[X[i]] = a;} //Aの受け取り(Xと関連付けながら)
    sort(X.begin(),X.end()); //Xを昇順にする
    if(X[0] != 1){
        ans = -1 ; // X_1が1じゃないなら不可能
    }
    else{
        for(int i = 0; i < M; i++){ //以降Nはi+1番目に大きいXより番号が大きく石のないマスのうち最大の番号(全て石がある場合はi+1番目に大きいXの値)
            if(i == M-1){
                int a = A[X[M-1-i]];
                if(a < N){
                    ans = -1; //最後の段階で1番目のマスにある石で埋めれないのであれば不可能
                }
                else{
                    ans += N * (N-1) /2; //埋めるのに必要な回数
                }
            }
            else{
                int a = A[X[M-1-i]],x=X[M-1-i];
                if(N-x < a){
                    ans += (N-x) * ( N - x + 1) /2; //このXにある石でそれより大きな番号のマス全てに石を置ける場合
                    N = x-1;//Nの更新
                }
                else{
                    ans += a * (2*N - 2*x + 1 - a)/2;//↑ができない場合、自身を空にして石をより大きな番号で空のますに順に置く
                    N -= a;//Nの更新
                }
            }
        }
    }
    cout << ans << "\n";//答えを出す
}