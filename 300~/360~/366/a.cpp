#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,T,A;
    cin >> N >> T >> A;
    N /= 2;
        if(T > N || A > N){
            cout << "Yes";
        }
        else {
            cout << "No";
        }
}