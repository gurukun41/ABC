#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll H, W, S1, S2;
    string X;
    cin >> H >> W >> S1 >> S2;
    S1--; S2--;
    vector <vector <char>> C(H, vector<char>(W));
    for(ll i = 0; i < H; i++){
        for(ll j = 0; j < W; j++){
            cin >> C.at(i).at(j);
        }
    }
    cin >> X;
    ll sizex = X.length();
    char x;
    for(ll i = 0; i < sizex; i++){
        x = X[i];
        if(x == 'L'){
            if(S2 == 0){
                continue;
            }
            else if(C.at(S1).at(S2-1) == '.'){
                S2 --;
            }
        }
        else if(x == 'R'){
            if(S2  == W-1){
                continue;
            }
            else if(C.at(S1).at(S2 + 1) == '.'){
                S2 ++;
            }
        }
        else if(x == 'U'){
            if(S1  == 0){
                continue;
            }
            else if(C.at(S1-1).at(S2) == '.'){
                S1 --;
            }
        }
        else{
            if(S1  == H-1){
                continue;
            }
            else if(C.at(S1+1).at(S2) == '.'){
                S1 ++;
            }
        }
    }
    std::cout << S1+1 << " " << S2+1;
}