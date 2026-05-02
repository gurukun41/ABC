#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;

/*
転倒数

i < j かつ a[i] > a[j] である組 (i,j) の個数。
隣接swapで配列を昇順にする最小回数にも等しい。

値が大きい場合や負の場合も、内部で座標圧縮して数える。
計算量 O(N log N)。
*/
template <class T>
ll inversion_number(vector<T> a) {
    vector<T> xs = a;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    atcoder::fenwick_tree<ll> fw((int)xs.size());
    ll inv = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        int x = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
        inv += i - fw.sum(0, x + 1);
        fw.add(x, 1);
    }
    return inv;
}

/*
使用例:
vector<int> a = {3, 1, 2};
cout << inversion_number(a) << "\n"; // 2: (3,1), (3,2)
*/
