#include<bits/stdc++.h>
using namespace std;

//約数列挙
vector<long long> makediv(long long n) {
    vector<long long> ld, ud;
    for (long long i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        ld.push_back(i);
        if (n / i != i) {
          ud.push_back(n / i);
        }
      }
    }
    reverse(ud.begin(), ud.end());
    ld.insert(ld.end(), ud.begin(), ud.end());
    return ld;
}

int main(){
    long long n; cin >> n;
    vector<long long> ans;
    ans = makediv(n);
    for(auto i: ans){
        cout << i << endl;
    }
}