#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;                                     // long long型の一次元
using vvl = vector<vl>;                                    // long long型の二次元配列
using vvvl = vector<vvl>;                                  // long long型の三次元配列
using vi = vector<int>;                                    // int型の一次元
using vvi = vector<vi>;                                    // int型の二次元配列
using vvvi = vector<vvi>;                                  // int型の三次元配列
#define rep(i, a, b) for (int i = (a); i < (int)(b); i++)  // for文の短縮
#define all(v) v.begin(), v.end()                          // all(v)でvの始まりと終わりのイテレーター

// 入力を受け取る
template <typename T>
T input() {
    T x;
    cin >> x;
    return x;
}

// a,bのうち最大のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// 素数判定
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

// 無限大の値
const long long INF = 1LL << 60;

template <class T>
void dfs_permutation(vector<T> &arr, int r, unordered_set<T> &selected, vector<T> &pattern, vector<vector<T>> &result) {
    if (r == 0) {
        result.push_back(pattern);
        return;
    }

    for (T v : arr) {
        if (selected.find(v) == selected.end()) {
            selected.insert(v);
            pattern.push_back(v);
            dfs_permutation(arr, r - 1, selected, pattern, result);
            pattern.pop_back();
            selected.erase(v);
        }
    }
}

template <class T>
vector<vector<T>> permutation(vector<T> &arr, int r) {
    if (arr.size() < r) {
        printf("permutation ERROR: r is larger than arr.size()\n");
        exit(1);
    }

    // 配列arrに、同じ値が含まれている可能性があるため、
    // indexを使って順列を列挙し、最後に元の配列の要素に戻す
    vector<int> indexes(arr.size());
    iota(indexes.begin(), indexes.end(), 0);

    unordered_set<int> selected;
    vector<int> pattern;
    vector<vector<int>> result_indexes;

    dfs_permutation<int>(indexes, r, selected, pattern, result_indexes);

    vector<vector<T>> result;
    for (vector<int> idx_pat : result_indexes) {
        vector<T> pat;
        for (int i : idx_pat) {
            pat.push_back(arr[i]);
        }
        result.push_back(pat);
    }
    return result;
}

int main() {
    ll N, K, X;
    cin >> N >> K >> X;
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];
    vector<string> aS;
    sort(all(S));
    for (ll i = 0; i < (1 << (N+1)); i++) {
        ll count = 0;
        rep(j, 0, N) {
            if (i & (1 << j)) {
                count++;
            }
        }
        if (count == K) {
            vector<string> T(K);
            ll x = 0;
            rep(j, 0, N) {
                if (i & (1 << j)) {
                    T[x] = S[j];
                    x++;
                }
            }
            do {
                string p = "";
                rep(y, 0, K) { p += T[y]; }
                aS.push_back(p);
            } while (next_permutation(all(T)));
        }
    }
    sort(all(aS));
    
    cout << aS[X-1] << "\n";
}