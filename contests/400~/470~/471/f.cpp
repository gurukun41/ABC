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
    ll N,K;scan(N,K);
    vector<pair<ll,string>> V;
    pair<ll,string> f = {0,"0"};
    pair<ll,string> max = {0,"0"};
    bool first = true;
    rep(i,0,N){
        string S;scan(S);
        bool change = false;
        // 最大かどうか
        rep(j,0,S.size()){
            if(S[j]=='0')continue;
            if(S.size()-j>max.first){
                pair<ll,string> old = f;
                f = {S.size(),S};
                string nf = "";
                rep(k,j,S.size()){
                    nf+=S[k];
                }
                max = {nf.size(),nf};
                change = true;
                if(first){
                    first = false;
                } else {
                    V.push_back(old);
                }
            } else if(S.size()-j == max.first){
                bool can = false;
                rep(k,j,S.size()){
                    if(S[k] < max.second[k-j]){
                        break;
                    } else if(S[k] > max.second[k-j]){
                        can = true;
                        break;
                    }
                }   
                if(can){
                    pair<ll,string> old = f;
                    f = {S.size(),S};
                    string nf = "";
                    rep(k,j,S.size()){
                        nf+=S[k];
                    }
                    max = {nf.size(),nf};
                    change = true;
                    if(first){
                        first = false;
                    } else {
                        V.push_back(old);
                    }
                }             
            }
        }
        if(change) continue;
        V.push_back(pair<ll,string>{S.size(),S});
    }

    sort(all(V));
    vector<pair<string,ll>> cand;
    cand.push_back({max.second+max.second[0],max.first});
    cand.push_back({f.second+f.second[0],f.first});
    rep(i,0,K-1){
        cand.push_back({V[V.size()-i-1].second+V[V.size()-i-1].second[0],V[V.size()-i-1].first});
    }
    sort(all(cand));

    bool usem = false;
    pair<string,ll> used;
    string ans = "";
    bool skip = false;
    rep(i,0,K+1){
        pair<string,ll> now = cand[K+1-1-i];
        if(!usem){
            if(pair<string,ll>{max.second+max.second[0],max.first} == now 
                || pair<string,ll>{f.second+f.second[0],f.first} == now){
                    usem = true;
                    used = now;
                    if(used == pair<string,ll>{max.second+max.second[0],max.first}){
                        used = {f.second+f.second[0],f.first};
                    }else {
                        used = {max.second+max.second[0],max.first};
                    }
            }
            rep(j,0,now.second){
                ans+=now.first[j];
            }

        } else {
            if(used == now && !skip){
                skip = true;
                continue;
            }
            rep(j,0,now.second){
                ans+=now.first[j];
            }
        }
    }

    vector<pair<string,ll>> cand2;
    V.push_back(f);
    rep(i,0,K){
        cand2.push_back({V[V.size()-i-1].second+V[V.size()-i-1].second[0],V[V.size()-i-1].first});
    }
    sort(all(cand2));

    string ans2 = "";
    rep(i,0,K){
        pair<string,ll> now = cand2[K-1-i];
        if(cand2[K-1].first[0]=='0'){
            break;
        }
        rep(j,0,now.second){
            ans2+=now.first[j];
        }
    }
    if(ans.size() > ans2.size())emit(ans);
    else if(ans.size() < ans2.size())emit(ans2);
    else if(ans > ans2)emit(ans);
    else emit(ans2);
    
}