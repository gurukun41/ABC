#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    string A;
    cin >> A ;
    if(A[1] == '.'){
        if(A[4] == '0') {
            if(A[3] == '0'){
                if(A[2] == '0'){
                    cout << A[0];
                }
                else{
                    cout << A[0] << A[1] << A[2];
                }
            }
            else{
                cout << A[0] << A[1] << A[2] << A[3];
            }
        } 
        else{
                cout << A[0] << A[1] << A[2] << A[3] << A[4];
        } 
    }
    else{
        if(A[5] == '0') {
            if(A[4] == '0'){
                if(A[3] == '0'){
                    cout << A[0] << A[1];
                }
                else{
                    cout << A[0] << A[1] << A[2] << A[3];
                }
            }
            else{
                cout << A[0] << A[1] << A[2] << A[3] << A[4];
            }
        } 
        else{
                cout << A[0] << A[1] << A[2] << A[3] << A[4] << A[5];
        } 
    }
}