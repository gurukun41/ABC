#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll n;
    ll num = 0;
    string s;
    cin >> n;
    for(ll i = 0; i < n-1; i ++){
        cin >> s;
        if(s == "sweet"){
            num ++;
        }
        else{
            num = 0;
        }
        if(num == 2){
            cout << "No";
            break;
        }
    }
    if(num != 2){

        cout << "Yes";
    }
}