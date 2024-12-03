#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N;
    cin >> N;
    vector < vector <vector<ll>>> A(100, vector<vector<ll>>(100,vector<ll>(100,0)));
    vector <vector<ll>> sumAz(100, vector<ll>(100,0)) ;
    vector <ll> sumAyz(100, 0);
    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                ll a;
                cin >> a;
                sumAz[i][j] += a;
                if(j > 0&&N!=1){
                    A[i][j][k] = sumAz[i][j] + A[i][j-1][k];
                }
                else{
                    A[i][j][k] = sumAz[i][j];
                }

            }
        }
    }
    ll Q;
    cin >> Q;
    rep(i,0,Q){
        ll Lx,Rx,Ly,Ry,Lz,Rz;
        ll sum=0;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        for(ll j = Lx-1 ; j < Rx; j ++){
            if(Lz > 1 && Ly >1){
            sum += (A[j][Ry-1][Rz-1]-A[j][Ry-1][Lz-2]-A[j][Ly-2][Rz-1]+A[j][Ly-2][Lz-2]);
            }
            else if (Lz > 1){
                sum += (A[j][Ry-1][Rz-1]-A[j][Ry-1][Lz-2]);
            }
            else if (Ly > 1){
                sum += (A[j][Ry-1][Rz-1]-A[j][Ly-2][Rz-1]);
            }
            else{
                sum += A[j][Ry-1][Rz-1];
            }

        }
        cout << sum << "\n";
    }
}