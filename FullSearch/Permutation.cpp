#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = i+1;
    }
    int ans = -1'000'000'000;
    do {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += p[i] * a[i];
        ans = max(ans,sum);
    }while(next_permutation(p.begin(),p.end()));
    cout << ans << endl;
}