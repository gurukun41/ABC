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
    ll i = 1;
    ll num = 0;
    vector<set<ll>> S(14);
    ll keta = 0;
    ll iketa = 0;
    ll nom = 1;
    while(num<N || nom){
        if(keta==iketa){
            nom = 1;
            S[keta].insert(i);
            i*=2;
            ll temp = i;
            ll count = 0;
            while(temp!=0){
                temp/=10;
                count++;
            }
            count--;
            iketa=count;
            num++;
        } else{
            nom = 0;
            ll tc = S[keta].size();
            rep(j,0,keta){
                for(ll x:S[j]){
                    for(ll y:S[keta-j-1]){
                        string s = to_string(x)+to_string(y);
                        S[keta].insert(stol(s));
                    }
                }
            }
            num+=S[keta].size()-tc;
            keta++;
        }
    }
    keta--;
    ll c = num-N;
    for (auto itr = rbegin(S[keta]); itr != rend(S[keta]); ++itr) {
        if(c==0){
            cout << *itr << "\n";
            return 0;
        }
        c--;
    }


}