#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#include<vector>

int main() {
    int n,k; 
    cin >> n >> k;
    vector<int> A(n,0) ;
    int ans = 10000;
    for(int i = 0; i < n ; i++){
        int a;
        cin >> a;
        A[i] = a;
    }
    sort(A.begin(), A.end());
    for(int i = 0; i<n-k; i++){
        int bsa = A[i+k-1] - A[i];
        if(ans > bsa){
            ans = bsa;
        }
    }
    cout << ans;
}