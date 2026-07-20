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
ll answer = 42;
ll N = 3, M = 4;
double ratio = 1.0 / 3.0;
string message = "Yes";
vl ans = {10, 20, 30};
vl next = {40, 50};
pl edge = {1, 2};
vvl matrix = {{1, 2}, {3, 4}};

emit(answer);               // 42\n
emit(ratio);                // 0.333333333333333\n
emit(N, M);                 // 3 4\n
emit(N, M, " ");            // 3 4\n
emit(N, M, "\n");           // 3\n4\n
emit(N, M, "");             // 34\n
emit(N, M, message);        // 3 4 Yes\n
emit(message);              // Yes\n
emit(edge);                 // 1 2\n
emit(ans);                  // 10 20 30\n
emit(ans, next);            // 10 20 30 40 50\n
emit(ans, next, "\n");      // 10\n20\n30\n40\n50\n
emit(edge, ans);            // 1 2 10 20 30\n
emit(matrix);               // 1 2 3 4\n
emit(ans, "\n");            // 10\n20\n30\n
emit(ans, ", ");            // 10, 20, 30\n
emit(ans, " ", "");         // 10 20 30（最後の改行なし）

vector<char> chars = {'a', 'b', 'c'};
emit(chars, "");            // abc\n
vs words = {"At", "Coder"};
emit(words, "");            // AtCoder\n
vs blocks = {"first\n", "second\n"};
emit(blocks, "", "");       // 要素内の改行だけを使って連結
```

- `emit(x, xs...)`: 各引数のpair・array・vectorを再帰的に展開し、末端の値を空白区切りで1行に出力する。
- 3引数以上で末尾が `""`, `" "`, `"\n"` のいずれかなら、その末尾を値ではなく区切り文字として使う。
- 上記の予約文字列は、3引数以上の `emit` では最後の出力値にできない。
- 単一のpair・array・vectorでは `emit(xs, delimiter, end)` として任意の区切りと終端を指定できる。
- `emit(xs, "\n")`: 再帰展開した末端の値を1行ずつ出力する。
- `string` は文字ごとに展開せず、1つの値として出力する。
- `float` / `double` / `long double` は、小数点以下15桁で出力する。変更した出力設定は呼び出し内で元に戻す。
- 空のarray/vectorは値を出力しない。すべて空なら `end` だけを出力する。
- `vector<pair>` や入れ子array/vectorも、構造を保たず末端の値まで平坦化する。

行列の行構造を保って出す場合は、行ごとに `emit` を呼ぶ。

```cpp
for (const vl &row : grid) emit(row);
```

## Yes / No

```cpp
yn(N < M);                  // Yes または No を1行

vb ok = {true, false, true};
yns(ok);                    // Yes\nNo\nYes\n
```

`emit(ok, "\n")` は `1/0` を出す。`Yes/No` が必要なら `yns(ok)` を使う。

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
