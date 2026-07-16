# base.cpp usage

`base` スニペットを展開した後に使う例。

## 入力

```cpp
// 複数の値
ll N, M;
scan(N, M);

// vector（先にサイズを確保する）
vl A(N);
scan(A);

// 二次元vectorも再帰的に読める
ll H, W;
scan(H, W);
vvl grid(H, vl(W));
scan(grid);

// stringのvector
vs S(N);
scan(S);

// pair / vector<pair>
pl edge;
scan(edge);
vpl edges(M);
scan(edges);

// array / vector<bool>
array<ll, 3> xyz;
scan(xyz);
vb flags(N);
scan(flags);
```

`scan(vector)` は現在の要素を順に読むため、入力前に必要なサイズを確保する。

## 出力

```cpp
vl ans = {10, 20, 30};
pl edge = {1, 2};

print(edge);                // 1 2\n
print(ans);                 // 10 20 30\n
prints(ans);                // 10\n20\n30\n
print(ans, ", ");           // 10, 20, 30\n
print(ans, " ", "");        // 10 20 30（最後の改行なし）

vector<char> chars = {'a', 'b', 'c'};
print(chars, "");           // abc\n
vs words = {"At", "Coder"};
print(words, "");           // AtCoder\n
vs blocks = {"first\n", "second\n"};
print(blocks, "", "");      // 要素内の改行だけを使って連結
```

- `print(xs, sep, end)`: 平坦なrangeを横に出力する。
- `prints(xs)`: rangeの各要素を1行ずつ出力する。
- 空rangeでは、`print` は `end` だけ、`prints` は何も出力しない。
- `vector<pair>` や入れ子rangeは問題ごとの形式が違うため、自動展開しない。
- 単一の数値や文字列は、これまでどおり `cout << x << '\n';` で出力する。

行列をそのまま出す場合は、行ごとに `print` を呼ぶ。

```cpp
for (const vl &row : grid) print(row);
```

## Yes / No

```cpp
yn(N < M);                  // Yes または No を1行

vb ok = {true, false, true};
yns(ok);                    // Yes\nNo\nYes\n
```

`prints(ok)` は `1/0` を出す。`Yes/No` が必要なら `yns(ok)` を使う。

## その他

```cpp
// 更新されたときだけtrue
ll mn = 1LL << 60;
ll mx = -(1LL << 60);
if (chmin(mn, 100LL)) {
    // mnが更新された
}
chmax(mx, 200LL);

// グリッド内判定
if (inside(nx, ny, H, W)) {
    // 0 <= nx < H かつ 0 <= ny < W
}

// ループと全range
rep(i, 0, N) {
    // i = 0, ..., N-1
}
sort(all(A));
```
