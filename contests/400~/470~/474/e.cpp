#include <bits/stdc++.h>
#include <atcoder/all>
#include <queue>
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

    static constexpr bool is_separator(string_view s) {
        return s.empty() || s == " " || s == "\n";
    }

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
    auto write_value(const T &x, string_view sep, bool &first) const
        -> decltype((cout << x, void())) {
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

void yn(bool a) {
    cout << (a ? "Yes\n" : "No\n");
}

bool inside(int x, int y, int h, int w) {
    return 0 <= x && x < h && 0 <= y && y < w;
}

int main(){
    ll T;scan(T);
    rep(_,0,T){
        ll N;scan(N);
        vl A(N);
        vl C(N);
        ll sum = 0;
        rep(i,0,N){
            ll a,b;scan(a,b);
            A[i] = a;
            C[i] = a-b;
            sum += a;
        }
        vector<pair<ll,pl>> AC(N);
        rep(i,0,N){
            AC[i] = {A[i],{C[i],i}};
        }
        sort(all(AC));
        // Aが最も小さくかつクーポンの特が小さいもの
        // これが複数回買い得る候補
        ll minp = AC[0].second.second;
        ll minA = A[minp];
        priority_queue<pl, vpl, greater<pl>> pqA;
        priority_queue<pl> pqC;
        rep(i,0,N){
            if(i==minp)continue;
            pqA.push({A[i],i});
            pqC.push({C[i],i});
        }
        vb by(N,0);
        ll ans = 0;
        ll ken = 0;
        ll count = 0;
        ans = sum;
        ken++;
        count++;
        by[minp] = true;

        while(count < N){
            if(ken>0){
                if(pqC.empty()){
                    ken=0;
                    continue;
                }
                ken--;
                pl c = pqC.top();
                pqC.pop();
                if(by[c.second])continue;
                ans -= c.first;
                by[c.second] = true;
                count++;
                continue;
            }
            if(pqA.empty()){
                pl c = pqC.top();
                pqC.pop();
                if(by[c.second])continue;
                ans -= c.first;
                ans += minA;
                by[c.second] = true;
                count++;
                continue;
            }else if(pqC.empty()){
                pl a = pqA.top();
                pqA.pop();
                if(by[a.second])continue;
                by[a.second] = true;
                count++;
                continue;
            }else{
                pl a = pqA.top();
                if(by[a.second]){
                    pqA.pop();
                    continue;
                }
                pl c = pqC.top();
                if(by[c.second]){
                    pqC.pop();
                    continue;
                }
                if( c.first >= C[a.second]-minA){
                    if(c.second == a.second){
                        pqA.pop();
                        by[a.second] = true;
                        count++;
                        ken++;
                        continue;
                    }
                    by[c.second] = true;
                    count++;
                    pqC.pop();
                    by[a.second] = true;
                    count++;
                    pqA.pop();
                    ans-=c.first;
                    continue;
                }else{
                    pqA.pop();
                    by[a.second] = true;
                    count++;
                    ans-=C[a.second];
                    ans+=minA;
                    continue;
                }
            }
        
        }
        emit(ans);
    }
}