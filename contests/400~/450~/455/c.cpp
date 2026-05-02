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

void yn(bool a) {
    if (a)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main(){
    ll N,K;cin >> N >> K;
    map<ll,ll> m;
    rep(i,0,N){
        ll a;cin >> a;
        if(m.contains(a)){
            m[a]+=a;
        } else {
            m[a]=a;
        }
    }
    vl A(0);
    for(const auto& [key, value] : m){
        A.push_back(value);
    }
    sort(all(A));
    ll ans = 0;

    rep(i,0,A.size()){
        ans += A[i];
    }
    rep(i,0,K){
        if((ll)A.size()-i-1 < 0){
            break;
        }else{
            ans -= A[(ll)A.size()-i-1];
        }
        
    }
    cout << ans << "\n";
}