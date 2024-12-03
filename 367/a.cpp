#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll A,B,C;
    cin >> A >> B >> C;
        if(B < C ){
            if(B < A && A < C){
                cout << "No";
            }
            else{
                cout << "Yes";
            }
            
        }
        else {
            if(C < A && A < B){
                cout << "Yes";
            }
            else{
                cout << "No";
            }
           
        }
}