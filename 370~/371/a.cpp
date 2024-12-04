#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    char Sab,Sac,Sbc;
    cin >> Sab >> Sac >> Sbc;
    ll A=0,B=0,C=0;
        if(Sab == '<'){
            B ++;
        }
        else {
            A ++;
        }
        if(Sac == '<'){
            C ++;
        }
        else {
            A ++;
        }
        if(Sbc == '<'){
            C ++;
        }
        else {
            B ++;
        }
        if(A==1){
            cout << 'A';
        }
        else if(B==1){
            cout << 'B';
        }
        else{
            cout <<'C';
        }
}