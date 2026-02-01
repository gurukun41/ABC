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
    ll T;cin >> T;
    vl ans(T,0);
    rep(_,0,T){
        ll N;cin >> N;
        vl R(N);
        vl seen(N,0);
        priority_queue<pl, vpl, greater<pl>> pq;
        rep(i,0,N){
            ll r;
            cin >> r;
            pq.push(pl{r,i});
            R[i] = r;
        }

        while(!pq.empty()){
            pl now = pq.top();
            pq.pop();
            if(seen[now.second]) continue;
            seen[now.second] = 1;
            if(now.second+1 < N){
                if(R[now.second+1] - now.first > 1){
                    ans[_] += R[now.second+1] - now.first -1;
                    R[now.second+1] = now.first+1;
                    pq.push(pl{R[now.second+1], now.second+1});
                    //cout << R[now.second+1] << "&" << now.second+1 << "\n";
                }
            }
            if(now.second-1 >= 0){
                if(R[now.second-1] - now.first > 1){
                    ans[_] += R[now.second-1] - now.first -1;
                    R[now.second-1] = now.first+1;
                    pq.push(pl{R[now.second-1], now.second-1});
                    //cout << R[now.second-1] << "&" << now.second-1 << "\n";
                }
            }
        }
    }
    rep(i,0,T){
        cout << ans[i] << "\n";
    }
}