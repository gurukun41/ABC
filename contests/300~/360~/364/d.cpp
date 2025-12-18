#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--) {
        int b, k;
        cin >> b >> k;
        auto f = [&](int x) -> bool {
            // (# of points in [b-x, b+x]) >= k
            auto lb = lower_bound(a.begin(), a.end(), b - x);
            auto ub = upper_bound(a.begin(), a.end(), b + x);
            return ub - lb >= k;
        };
        int ng = -1, ok = (int) 2e8 + 10;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (f(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << '\n';
    }
}
