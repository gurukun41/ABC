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

//ユークリッドの互除法
long long gcd(long long n, long long m){
    if (n < m) swap(n, m);
    if (m == 0) return n;
    return gcd(m, n%m);
}

// 比較
bool compmf(const pair<ld,ll>& a, const pair<ld,ll>& b){
    return a.first < b.first;
}

const ld PI = acos(-1.0L);

int main(){
    ll N,Q;cin >> N >> Q;
    map<pl,ll> m1,m2,m3,m4;
    vpl pt(N);
    rep(i,0,N){
        ll X,Y;
        cin >> X >> Y;
        if(X>0&&Y>0){
            ll same = gcd(X,Y);
            pl p = pl{X/same,Y/same};
            pt[i] = p;
            if(m1.contains(p)) {
                m1[p]++;
            }
            else {
                m1[p] = 1;
            }
        } else if(X<0&&Y>0){
            ll same = gcd(-1*X,Y);
            pl p = pl{X/same,Y/same};
            pt[i] = p;
            if(m2.contains(p)) {
                m2[p]++;
            }
            else {
                m2[p] = 1;
            }            
        } else if (X<0&&Y<0){
            ll same = gcd(-1*X,-1*Y);
            pl p = pl{X/same,Y/same};
            pt[i] = p;
            if(m3.contains(p)) {
                m3[p]++;
            }
            else {
                m3[p] = 1;
            }
        } else if (X>0 && Y < 0) {
            ll same = gcd(X,-1*Y);
            pl p = pl{X/same,Y/same};
            pt[i] = p;
            if(m4.contains(p)) {
                m4[p]++;
            }
            else {
                m4[p] = 1;
            }
        } else if (X==0){
            if(Y>0){
                pl p = pl{0,1};
                pt[i] = p;
                if(m2.contains(p)) {
                    m2[p]++;
                }
                else {
                    m2[p] = 1;
                }                
            } else {
                pl p = pl{0,-1};
                pt[i] = p;
                if(m4.contains(p)) {
                    m4[p]++;
                }
                else {
                    m4[p] = 1;
                }               
            }
        } else {
            if(X>0){
                pl p = pl{1,0};
                pt[i] = p;
                if(m1.contains(p)) {
                    m1[p]++;
                }
                else {
                    m1[p] = 1;
                }                
            } else {
                pl p = pl{-1,0};
                pt[i] = p;
                if(m3.contains(p)) {
                    m3[p]++;
                }
                else {
                    m3[p] = 1;
                }               
            }            
        }
    }

    vector<pair<ld,ll>> con;
    for (const auto& [key, value] : m1) {
        con.push_back(pair<ld, ll>{atan2(key.second,key.first), value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-4.0*PI, value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-2.0*PI, value});
    }
    for (const auto& [key, value] : m2) {
        con.push_back(pair<ld, ll>{atan2(key.second,key.first), value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-4.0*PI, value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-2.0*PI, value});
    }
    for (const auto& [key, value] : m3) {
        con.push_back(pair<ld, ll>{atan2(key.second,key.first), value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-4.0*PI, value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-2.0*PI, value});
    }
    for (const auto& [key, value] : m4) {
        con.push_back(pair<ld, ll>{atan2(key.second,key.first), value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-4.0*PI, value});
        con.push_back(pair<ld, ll>{atan2(key.second,key.first)-2.0*PI, value});
    }
    sort(all(con));

    vector<pair<ld,ll>> sum(con.size());
    rep(i,0,con.size()){
        if(i == 0){
            sum[i] = con[i];
        } else {
            sum[i] = pair<ld,ll>{con[i].first, con[i].second + sum[i-1].second};
        }
    }
    vl ans(Q);

    rep(_,0,Q){
        ll A,B;cin >> A >> B;
        A--;B--;
        ld f = atan2(pt[A].second,pt[A].first);
        ld s = atan2(pt[B].second,pt[B].first);
        if(f < s){
            s = s - 2.0*PI;
        }
        auto lb1 = lower_bound(all(sum), pair<ld,ll>{f,0}, compmf);
        auto lb2 = lower_bound(all(sum), pair<ld,ll>{s,0}, compmf);

        lb2--;
        ans[_] = (*lb1).second - (*lb2).second;

    }
    rep(i,0,Q){
        cout << ans[i] << "\n";
    }

}