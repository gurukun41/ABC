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
    vl ans(0);
    ll p = N;

    ll num = A[p-1]+A[0];
    bool ok = true;
    rep(i,0,N/2){
        if(A[i]+A[p-1-i] != num){
            ok = false;
            break;
        }
    }

    if(N%2==1){
        if(A[N/2] != num){
            ok = false;
        }
    }
    if(ok){
        ans.push_back(num);
    }

    while(true){
        if(p==1){
            p--;
            break;
        }
        if(A[p-1] == A[p-2]){
            p--;
        } else {
            p--;
            break;
        }
    }

    if(p!=N-1&&p!=0){
        num = A[p];
        ok = true;
        rep(i,0,p/2){
            if(A[i]+A[p-1-i] != num){
                ok = false;
                break;
            }
        }
        if(p%2==1){
            if(A[p/2] != num){
                ok = false;
            }
        }
        if(ok){
            ans.push_back(num);
        } 
    }
    if(p==0){
        ans.push_back(A[p]);
    }
    rep(i,0,ans.size()){
        cout << ans[ans.size()-i-1];
        if(i != ans.size() -1){
            cout << " ";
        }else{
            cout << "\n";
        }
    }
}