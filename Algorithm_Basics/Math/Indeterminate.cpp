#include<bits/stdc++.h>
using namespace std;

//一次不定式を解く
tuple<long long, long long, long long> extgcd(long long n, long long m) {
    if (n < m){
      auto [g, x, y] = extgcd(m, n);
      return make_tuple(g, y, x);
    }
    if (m == 0) return make_tuple(n, 1, 0);
    long long q = n / m;
    long long r = n % m;
    auto [g, x, y] = extgcd(m, r);
    return make_tuple(g, y, x-y*q);
  }

int main(){
    long long n,m; cin >> n >> m;
    tuple<long long, long long, long long> ans;
    ans = extgcd(n, m);
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl;
}