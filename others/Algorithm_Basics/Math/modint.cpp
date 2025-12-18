#include<bits/stdc++.h>
using namespace std;
#include<atcoder/modint>
typedef atcoder::modint998244353 mint;

//modint構造体
int main(){
  // 1000000000 = 1755647 (mod 998244353)
  cout << mint(1000000000).val() << '\n';
  // -1 = 998244352 (mod 998244353)
  cout << mint(-1).val() << '\n';
  // 499122177*2 = 1 (mod 998244353)
  cout << mint(2).inv().val() << '\n';
  // 2^6 = 64 (mod 998244353)
  cout << mint(2).pow(6).val() << '\n';
  // 2^123456789 = 952154659 (mod 998244353)
  cout << mint(2).pow(123456789).val() << '\n';
}