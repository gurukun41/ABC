# ABC library

競技中に「貼る・見る・思い出す」ためのライブラリ。

きれいなヘッダライブラリというより、ABC中に詰まったときにすぐ参照できる実戦用メモ集。
`main()` を含むサンプル系ファイルもあるので、必要な部分をコピーして使う。

## 直下

- `base.cpp`: 共通テンプレート。`ll`, `vector` alias, `rep`, `all`, `chmax/chmin`, `yn`/`yns`, 再帰入力`scan`, 複数値/pair/array/vectorの再帰出力`emit`（浮動小数点は15桁）, `inside(x,y,h,w)`
- `base_usage.md`: `base.cpp` の各機能を忘れたときに見る使用例
- `input.cpp`: `cin` から1つ読み込んで返す `input<T>()`
- `isPrime.cpp`: 試し割りによる素数判定
- `LazySegmentTree.cpp`: 自作遅延セグ木。区間加算・区間和、区間代入・区間最小値
- `README.md`: このライブラリ全体の目録

## Norms

STL や構文を忘れたときに見るメモ。

- `lower_and_upper.cpp`: `lower_bound` / `upper_bound` の使い方、index取得、個数取得
- `lamda.cpp`: ラムダ式によるメモ化再帰
- `map.cpp`: `map` の挿入、取得、存在確認、削除、走査
- `multiset.cpp`: `multiset` の最小値・最大値、1個削除、全削除、`lower_bound`
- `pair.cpp`: `pair` の構造化束縛、コピーと参照、`vector<pair>` の走査
- `priority_queue.cpp`: 最大ヒープ、最小ヒープ、`push/top/pop`
- `queue.cpp`: `queue` の `push/front/pop`
- `set.cpp`: `set` の挿入、検索、`lower_bound`、削除、走査
- `setprecision.cpp`: 小数出力の `fixed << setprecision(...)`
- `stack.cpp`: `stack` の `push/top/pop`

## ACLs

AtCoder Library の使い方テンプレ。

- `DSU.cpp`: `atcoder::dsu`。連結、同一判定、leader、size
- `Fenwick.cpp`: `atcoder::fenwick_tree`。一点加算・区間和
- `Segment.cpp`: `atcoder::segtree`。RMQ/RSQなどの基本形
- `LazySegment.cpp`: `atcoder::lazy_segtree`。区間加算・区間最小値の例
- `mint.cpp`: `modint998244353` と `Combination`。nCr/nPr/nHk
- `Math.cpp`: `pow_mod`, `inv_mod`, `crt`, `floor_sum`
- `String.cpp`: `z_algorithm`, `suffix_array`, `lcp_array`
- `Convolution.cpp`: 畳み込み。`convolution`, `convolution_ll`
- `SCC.cpp`: 強連結成分分解
- `TwoSAT.cpp`: 2-SAT
- `MaxFlow.cpp`: 最大流。二部マッチングにも使う
- `MinCostFlow.cpp`: 最小費用流。割当問題、最小コストマッチング向け

## Algorithm

典型アルゴリズムと前処理。

- `BinarySearch.cpp`: めぐる式二分探索
- `CoordinateCompression.cpp`: 座標圧縮
- `CumulativeSum.cpp`: 一次元・二次元累積和
- `Imos.cpp`: 一次元・二次元 imos
- `LIS.cpp`: 最長増加部分列。狭義/広義、各位置のLIS長
- `SubsetEnumeration.cpp`: bit の部分集合列挙
- `TwoPointers.cpp`: 尺取り法の典型。非負配列で和がK以下の区間数

## Graph

グラフ・木の頻出部品。

- `DFS.cpp`: 再帰DFS、連結成分番号
- `BFS.cpp`: unweighted graph の最短距離
- `BFS_Grid.cpp`: グリッドBFS、4近傍/8近傍方向配列
- `Dijkstra.cpp`: 非負重みグラフの単一始点最短路
- `ZeroOneBFS.cpp`: 辺重みが0/1のグラフの最短路
- `WarshallFloyd.cpp`: 全点対最短路、負閉路判定
- `TopologicalSort.cpp`: DAG のトポロジカルソート
- `EulerTour.cpp`: 木のオイラーツアー。部分木を区間に変換
- `LCA.cpp`: 最近共通祖先、木上距離
- `TreeDiameter.cpp`: 木の直径
- `Bipartite.cpp`: 二部グラフ判定

## DataStructure

ACLだけでは少し足りないデータ構造・応用。

- `WeightedUnionFind.cpp`: 重み付きUnion-Find。差分制約、ポテンシャル管理
- `FenwickRangeAdd.cpp`: Fenwick Tree 2本による区間加算・区間和
- `InversionNumber.cpp`: 座標圧縮 + Fenwick Tree による転倒数

## Math

整数・数論系。

- `PrimeTools.cpp`: 素数判定、素因数分解、約数列挙、エラトステネスの篩、SPF
- `ModMath.cpp`: modpow、拡張Euclid、mod逆元、floor/ceil div
- `MatrixPower.cpp`: 行列積、行列累乗。`mint` と組み合わせるとmod行列累乗になる

## String

文字列処理。

- `RunLengthEncoding.cpp`: 文字列・vector のランレングス圧縮
- `RollingHash.cpp`: ローリングハッシュ。部分文字列比較向け
