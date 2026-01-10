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
    vpl pairs(0);
    pair tmp = {-1, 0};
    ll del = 0;
    rep(i,0,N){
        ll A;cin >> A;
        if(tmp.first == -1){
            tmp = {A,1};
        } else if(tmp.first != A){
            pairs.push_back(tmp);
            tmp = {A, 1};
        } else {
            tmp.second++;
            if(tmp.second == 4){
                del += 4;
                if(pairs.size() > 0){
                    tmp = pairs[pairs.size()-1];
                    pairs.pop_back();
                } else {
                    tmp = {-1,0};
                }
            }
        }
    }
    cout << N-del << "\n";
}