#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)


int main() {
    ll N;
    cin >> N;
    vector<ll> K(N);
    ll sumK = 0;
    rep(i,0,N){
        ll k;
        cin >> k;
        K[i] = k;
        sumK += k;
    }
    ll ans = sumK;
    if(sumK%2==0){
        sumK /=2;
    }
    else{
        sumK = sumK/2 +1;
    }
    auto dfs = [&](auto dfs, ll i,ll j,ll sum) -> void{
        
        if(i==N-1){
            
            if(j==1){
                if(sum < sumK){
                    sum +=K[i];
                }
            }
            if(ans > sum && sum >= sumK){
                ans = sum;
            }
            
            
        }
        else{
            
                if(j==1){
                    if(sum < sumK){
                        sum +=K[i];
                    }
                    dfs(dfs,i+1,0,sum);
                    dfs(dfs,i+1,1,sum);
                }
                else{
                    //cout << i;
                    dfs(dfs,i+1,0,sum);
                    dfs(dfs,i+1,1,sum);
                }
            
        }
    };
    dfs(dfs,0,0,0);
    dfs(dfs,0,1,0);
    /*do{
        ll sum=0;
        for(ll i =0;i< N;i++){
            sum += K[i];
            if(sum >= sumK){
                if(ans > sum){
                    ans = sum;
                }
                break;
            }
        }
    } while(next_permutation(K.begin(),K.end())&&sumK!= ans);*/
    std::cout << ans;
}