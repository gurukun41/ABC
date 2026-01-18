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
    string S;cin >> S;

    /*vl A(N+1);
    A[0] = 0;
    rep(i,1,N+1){
        A[i] = A[i-1];
        if(S[i-1] == 'A'){
            A[i]++;
        } else if(S[i-1] == 'B'){
            A[i]--;
        }
    }*/

    vl A(N);
    rep(i,0,N){
        if(S[i] == 'A'){
            A[i] = -1;
        } else if(S[i] == 'B'){
            A[i] = 1;
        } else {
            A[i] = 0;
        }
        if(i>0){
            A[i] += A[i-1];
        }
    }
    ll ans = 0;
    
    for (ll l = 0; l < N; l++) {
        ll sum = 0;
        ll r = l; 
        
        while (r < N && sum + A[r] < 0) {
            sum += A[r];
            r++;
        }
        
        ans += (r - l);
    }

    /*for (ll r = N-1; r >= 0; r--) {
        ll sum = 0;
        ll l = r; 
        
        while (l >= 0 && sum + A[l] < 0) {
            sum += A[l];
            l--;
        }
        
        ans += (r - l);
    }*/
    
    cout << ans << endl;
}