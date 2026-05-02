#include <bits/stdc++.h>
#include <atcoder/twosat>
using namespace std;
using ll = long long;

/*
2-SAT

真偽値変数 x_i に対する OR 条件の集まりを満たせるか判定する。
「AかBの少なくとも一方を満たす」という制約が大量にあるときに使う。

add_clause(i, f, j, g): (x_i == f) OR (x_j == g)
satisfiable(): 条件を満たせるか
answer(): satisfiable後に解を返す
*/
void two_sat_example(int n) {
    atcoder::two_sat ts(n);

    // 例: x0 または !x1
    ts.add_clause(0, true, 1, false);

    // 例: x2 を true に固定したいなら (x2 or x2)
    if (n >= 3) ts.add_clause(2, true, 2, true);

    if (ts.satisfiable()) {
        vector<bool> ans = ts.answer();
        (void)ans;
    }
}
