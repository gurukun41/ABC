#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve(ll mid){
    bool ans = false;
    //動作
    return ans;
}

int main(){
    ll ng = 1000; //必ず条件を満たさない数
    ll ok = -1; //必ず条件を満たす数

    //めぐる式二分探索
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }
}