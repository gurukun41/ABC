#include<bits/stdc++.h>
using namespace std;

// n 以下の素数のリストを返す(エラトステネスの篩)
vector<long long> enumerate_prime(long long n) {
    vector<bool> mark(n+1);
    vector<long long> ret;
    mark[1] = true;
    for (long long i=2; i<=n; i++){
      if (mark[i]){
        continue;
      }
      ret.push_back(i);
      for (long long j=2*i; j<=n; j+=i){
        mark[j] = true;
      }
    }
    return ret;
}

int main(){
    long long n; cin >> n;
    vector<long long> ans;
    ans = enumerate_prime(n);
    for(auto i: ans){
        cout << i << endl;
    }
}