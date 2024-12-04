#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N;
    cin >> N;
    vector <ll> A(N);
    vector <ll> B(N);
    rep(i,0,N){
       cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    rep(i,0,N){
       cin >> B[i];
    }
    sort(B.rbegin(),B.rend());
    cout << A[0]+B[0];
    
}