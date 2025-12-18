#include<bits/stdc++.h>
using namespace std;

//ビット全探索
int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool ans = false;
    for (int s = 0; s < 1<<n; s++){
        int sum = 0;
        for (int i = 0; i < n; i++){
            if (s >> i & 1) sum += a[i];
        }
        if (sum == k) ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
}