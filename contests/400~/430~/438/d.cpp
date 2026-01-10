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

const long long INF = 1LL << 60;

int main(){
    ll N;cin >> N;
    vl A(N), B(N), C(N);
    rep(i,0,N){
        cin >> A[i];
    }
    rep(i,0,N){
        cin >> B[i];
    }
    rep(i,0,N){
        cin >> C[i];
    }

    vl sumAB(N), sumCB(N);
    ll sAB =0, sCB =0;
    ll sumB = 0;
    ll maxAB = -INF;
    ll maxCB = -INF;
    rep(i,0,N){
        sumB += B[i];
        sAB = sAB + (A[i]-B[i]);
        chmax(maxAB,sAB);
        sCB = sCB + (C[N-i-1]-B[N-1-i]);
        chmax(maxCB,sCB);
        sumAB[i] = maxAB;
        sumCB[N-1-i] = maxCB;
    }

    ll max = -INF;
    rep(i,0,N-2){
        ll s = sumAB[i] + sumCB[i+2];
        if(s > max){
            max = s;
        }
    }

    cout << sumB + max << "\n";
}