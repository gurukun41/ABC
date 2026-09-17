#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
using ld = long double;
using mint = atcoder::modint998244353;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvvb = vector<vvb>;
using vs = vector<string>;
using vvs = vector<vs>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
#define rep(i, a, b) for (ll i = (a); i < (ll)(b); i++)
#define all(v) v.begin(), v.end()

struct Scanner {
    template <typename T>
    void read(T &x) const {
        cin >> x;
    }

    template <typename T, typename U>
    void read(pair<T, U> &p) const {
        read(p.first);
        read(p.second);
    }

    template <typename T, size_t N>
    void read(array<T, N> &a) const {
        for (T &x : a) read(x);
    }

    template <typename T>
    void read(vector<T> &v) const {
        for (T &x : v) read(x);
    }

    void read(vector<bool> &v) const {
        for (size_t i = 0; i < v.size(); i++) {
            bool x;
            cin >> x;
            v[i] = x;
        }
    }

    template <typename... Ts>
    void operator()(Ts &...xs) const {
        (read(xs), ...);
    }
};

struct Emitter {
    static constexpr int floating_precision = 15;

    static constexpr bool is_separator(string_view s) { return s.empty() || s == " " || s == "\n"; }

    template <typename T>
    static constexpr false_type container_tag(const T &) {
        return {};
    }

    template <typename T, typename U>
    static constexpr true_type container_tag(const pair<T, U> &) {
        return {};
    }

    template <typename T, size_t N>
    static constexpr true_type container_tag(const array<T, N> &) {
        return {};
    }

    template <typename T, typename Alloc>
    static constexpr true_type container_tag(const vector<T, Alloc> &) {
        return {};
    }

    template <typename T>
    auto write_value(const T &x, string_view sep, bool &first) const -> decltype((cout << x, void())) {
        if (!first) cout << sep;
        first = false;
        if constexpr (is_floating_point_v<decay_t<T>>) {
            auto flags = cout.flags();
            auto precision = cout.precision();
            cout << fixed << setprecision(floating_precision) << x;
            cout.flags(flags);
            cout.precision(precision);
        } else {
            cout << x;
        }
    }

    template <typename T, typename U>
    void write_value(const pair<T, U> &p, string_view sep, bool &first) const {
        write_value(p.first, sep, first);
        write_value(p.second, sep, first);
    }

    template <typename T, size_t N>
    void write_value(const array<T, N> &a, string_view sep, bool &first) const {
        for (const T &x : a) write_value(x, sep, first);
    }

    template <typename T, typename Alloc>
    void write_value(const vector<T, Alloc> &v, string_view sep, bool &first) const {
        for (const auto &x : v) write_value(x, sep, first);
    }

    template <typename Tuple, size_t... Is>
    void write_values(const Tuple &xs, string_view sep, string_view end, index_sequence<Is...>) const {
        bool first = true;
        (write_value(get<Is>(xs), sep, first), ...);
        cout << end;
    }

    template <typename T, typename... Ts>
    void operator()(const T &x, const Ts &...xs) const {
        auto values = tie(x, xs...);
        constexpr size_t count = sizeof...(Ts) + 1;
        constexpr bool first_is_container = decltype(container_tag(declval<const T &>()))::value;

        if constexpr (first_is_container && count == 2) {
            using Sep = decltype(get<1>(values));
            if constexpr (is_convertible_v<Sep, string_view>) {
                write_values(values, get<1>(values), "\n", make_index_sequence<1>{});
                return;
            }
        }

        if constexpr (first_is_container && count == 3) {
            using Sep = decltype(get<1>(values));
            using End = decltype(get<2>(values));
            if constexpr (is_convertible_v<Sep, string_view> && is_convertible_v<End, string_view>) {
                write_values(values, get<1>(values), get<2>(values), make_index_sequence<1>{});
                return;
            }
        }

        if constexpr (count >= 3) {
            using Last = decltype(get<count - 1>(values));
            if constexpr (is_convertible_v<Last, string_view>) {
                string_view last = get<count - 1>(values);
                if (is_separator(last)) {
                    write_values(values, last, "\n", make_index_sequence<count - 1>{});
                    return;
                }
            }
        }

        write_values(values, " ", "\n", make_index_sequence<count>{});
    }
};

inline constexpr Scanner scan{};
inline constexpr Emitter emit{};

template <typename T>
inline bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
inline bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Range>
void yns(const Range &xs) {
    for (const auto &x : xs) cout << (x ? "Yes\n" : "No\n");
}

void yn(bool a) { cout << (a ? "Yes\n" : "No\n"); }

bool inside(int x, int y, int h, int w) { return 0 <= x && x < h && 0 <= y && y < w; }

bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) return false;
    }
    return true;
}

// 素因数分解: {{prime, exponent}, ...}
vector<pair<ll, int>> prime_factorization(ll n) {
    vector<pair<ll, int>> ret;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        ret.push_back({p, e});
    }
    if (n > 1) ret.push_back({n, 1});
    return ret;
}

// 約数列挙: 昇順
vector<ll> divisors(ll n) {
    vector<ll> small, large;
    for (ll d = 1; d * d <= n; d++) {
        if (n % d != 0) continue;
        small.push_back(d);
        if (d * d != n) large.push_back(n / d);
    }
    reverse(large.begin(), large.end());
    small.insert(small.end(), large.begin(), large.end());
    return small;
}

int main() {
    int X;
    scan(X);
    if (X == 0) {
        emit("R");
        return 0;
    }  else if(X==1){
        emit("ARC");
        return 0;
    }
    string S = "";
    ll rem = 0;

    while(true) {
        vl div = divisors(X);
        ll cand, cand2;
        if (div.size() % 2 == 0) {
            cand = div[div.size() / 2 - 1];
            cand2 = div[div.size() / 2];
        } else {
            cand = div[div.size() / 2];
            cand2 = div[div.size() / 2];
        }
        vl rdiv = divisors(rem);
        ll rcand, rcand2;
        if(rem==0){
            rcand=0;
            rcand2=0;
        }else if(rem==1){
            rcand=1;
            rcand2=0;
        }else{
            if (rdiv.size() % 2 == 0) {
                rcand = rdiv[rdiv.size() / 2 - 1];
                rcand2 = rdiv[rdiv.size() / 2];
            } else {
                rcand = rdiv[rdiv.size() / 2];
                rcand2 = rdiv[rdiv.size() / 2];
            }
        }
        ll lsize = 2*cand+2*cand2-1;
        ll rsize = 2*rcand+2*rcand2+1;
        if(rem==0) rsize = 0;
        else if(rem==1) rsize = 3;
        if(lsize+rsize>100){
            X--;rem++;
            continue;
        }
        rep(j, 0, cand) { S += "AR"; }
        rep(j, 0, cand2 - 1) { S += "CR"; }
        S += "C";
        rep(j, 0, rcand) { S += "AR"; }
        rep(j, 0, rcand2 - 1) { S += "CR"; }
        if(rcand !=0 )S += "C";
        break;
    }
    emit(S);
    emit(S.size());
}