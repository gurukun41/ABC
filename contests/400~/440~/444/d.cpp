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
    ll N;cin >> N;
    vl A(N);rep(i,0,N)cin >> A[i];
    sort(all(A));
    map<ll,ll> m;
    rep(i,0,N){
        if(m.contains(A[i])){
            m[A[i]]++;
        } else {
            m[A[i]] = 1;
        }
    }
    ll now = 0;
    ll temp = 0;
    ll sum = N;
    string ans = "";

    for(const auto& [key, value] : m){
        
        while(now < key){
            temp = sum + temp;
            string c = to_string((temp)%10);
            char C = c[0];
            ans = C + ans;
            now++;
            temp/=10;
        }
        sum-=value;
    }
    
    while(temp>0){
        string c = to_string((temp)%10);
        char C = c[0];
        ans = C + ans;
        now++;
        temp/=10;        
    }
    cout << ans << "\n";
}