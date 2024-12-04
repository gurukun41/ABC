#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    string S;
    cin >> S;
    ll size = S.size()-1;
    if(S[size]=='n'&&S[size-1]=='a'&&S[size-2]=='s'){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    
}