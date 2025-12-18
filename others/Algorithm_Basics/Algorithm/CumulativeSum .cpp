#include<bits/stdc++.h>
using namespace std;
using ll = long long;

//累積和

vector<ll> A(10000);
vector<ll> S(10000);
int N;

void make_table(){ //配列を作る
    for (int i = 0; i < N; i++){
        S[i + 1] = S[i] + A[i];
    }
}

void calc_sum(int l, int r){ // 連続した要素の和を計算, [l, r], 0-indexed
    cout << S[r + 1] - S[l] << endl;
}

int main(){
    cin >> N;for(int i = 0; i < N; i ++){cin >> A[i];}
    make_table();
    int l, r;cin >> l >> r;
    calc_sum(l,r);
}