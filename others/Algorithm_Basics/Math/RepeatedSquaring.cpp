#include<bits/stdc++.h>
using namespace std;

//繰り返し二乗法
long long modpow(long long x, long long n, long long m){
    if (n == 0) return 1 % m;
    x = ((x % m) + m) % m;
    if (n % 2 == 0){
        long long r = modpow(x, n/2, m);
        return r * r % m;
    }else{
        long long r = modpow(x, n/2, m);
        return r * r % m * x % m;
    }
}

int main(){
    long long x, n, m; cin >> x >> n >> m;
    cout << modpow(x,n,m) << endl;
}