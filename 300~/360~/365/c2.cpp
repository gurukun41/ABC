#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n);
    for(auto &v : a) cin >> v;
    ll s = accumulate(a.begin(), a.end(), 0ll);
    if(s <= m) {
        cout << "infinite" << endl;
        return 0;
    }
    int ok = 0, ng = 1000000000;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) >> 1;
        cout << mid << endl;
        ll tmp = 0;
        for(auto v : a) tmp += min(mid, v);
        if(tmp <= m)
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
}