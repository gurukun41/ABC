#include<bits/stdc++.h>
using namespace std;

//素数判定
bool is_prime(long long n) {
    if (n <= 1) {
      return false;
    }
    for (long long i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
}

int main(){
    long long n; cin >> n;
    if(is_prime(n)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}