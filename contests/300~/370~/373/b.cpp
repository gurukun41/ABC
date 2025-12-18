#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    string S;
    vector <ll> places(26);
    ll ans=0;
    cin >> S;
    rep(i,0,26){
        if(S[i]=='A'){
            places[0] = i;
        }
        else if(S[i]=='B'){
            places[1] = i;
        }
        else if(S[i]=='C'){
            places[2] = i;
        }
        else if(S[i]=='D'){
            places[3] = i;
        }
        else if(S[i]=='E'){
            places[4] = i;
        }
        else if(S[i]=='F'){
            places[5] = i;
        }
        else if(S[i]=='G'){
            places[6] = i;
        }
        else if(S[i]=='H'){
            places[7] = i;
        }
        else if(S[i]=='I'){
            places[8] = i;
        }
        else if(S[i]=='J'){
            places[9] = i;
        }
        else if(S[i]=='K'){
            places[10] = i;
        }
        else if(S[i]=='L'){
            places[11] = i;
        }
        else if(S[i]=='M'){
            places[12] = i;
        }
        else if(S[i]=='N'){
            places[13] = i;
        }
        else if(S[i]=='O'){
            places[14] = i;
        }
        else if(S[i]=='P'){
            places[15] = i;
        }
        else if(S[i]=='Q'){
            places[16] = i;
        }
        else if(S[i]=='R'){
            places[17] = i;
        }
        else if(S[i]=='S'){
            places[18] = i;
        }
        else if(S[i]=='T'){
            places[19] = i;
        }
        else if(S[i]=='U'){
            places[20] = i;
        }
        else if(S[i]=='V'){
            places[21] = i;
        }
        else if(S[i]=='W'){
            places[22] = i;
        }
        else if(S[i]=='X'){
            places[23] = i;
        }
        else if(S[i]=='Y'){
            places[24] = i;
        }
        else if(S[i]=='Z'){
            places[25] = i;
        }
    }
    rep(i,1,26){
        ans += abs(places[i] - places[i-1]);
    }
    cout << ans;
    
}