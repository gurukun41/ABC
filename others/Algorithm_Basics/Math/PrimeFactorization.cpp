#include<bits/stdc++.h>
using namespace std;

//素因数分解
vector<pair<long long, int>> prime_factorization(long long n) {
    vector<pair<long long, int>> ret;
    for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        int a = 0;
        while (n % i == 0) {
          a++;
          n /= i;
        }
        ret.push_back(pair(i, a));
      }
    }
    if (n > 1){
      ret.push_back(pair(n, 1));
    }
    return ret;
  }

int main(){
    long long n; cin >> n;
    vector<pair<long long,int>> ans;
    ans = prime_factorization(n);
    for(auto i: ans){
        cout << i.first << "^" << i.second << endl;
    }
}