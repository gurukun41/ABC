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
bool compp(const pair<pl, ll>& a, const pair<pl, ll>& b){
    return a.first.second * b.first.first > b.first.second * a.first.first;
}

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
            ll same = gcd(-X,Y);
            pl p = pl{X/same,Y/same};
            pt[i] = p;
            if(m2.contains(p)) {
                m2[p]++;
            }
            else {
                m2[p] = 1;
            }            
        } else if (X<0&&Y<0){
            ll same = gcd(-X,-Y);
            pl p = pl{X/same,Y/same};
            pt[i] = p;
            if(m3.contains(p)) {
                m3[p]++;
            }
            else {
                m3[p] = 1;
            }
        } else if (X>0 && Y < 0) {
            ll same = gcd(X,Y);
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
                    m4[p]++;
                }
                else {
                    m3[p] = 1;
                }               
            }            
        }
    }


    vector<pair<pl, ll>> v1(0);
    for (const auto& [key, value] : m1) {
        v1.push_back(pair<pl, ll>{key, value});
    }
    sort(all(v1),compp);

    vector<pair<pl, ll>> v2(0);
    for (const auto& [key, value] : m2) {
        v2.push_back(pair<pl, ll>{key, value});
    }
    sort(all(v2),compp);

    vector<pair<pl, ll>> v3(0);
    for (const auto& [key, value] : m3) {
        v3.push_back(pair<pl, ll>{key, value});
    }
    sort(all(v3),compp);

    vector<pair<pl, ll>> v4(0);
    for (const auto& [key, value] : m4) {
        v4.push_back(pair<pl, ll>{key, value});
    }
    sort(all(v4),compp);

    vector<vector<pair<pl,ll>>> sum(2,vector<pair<pl,ll>>(0));
    rep(i,0,v1.size()){
        if(i==0){
            sum[0].push_back(pair<pl, ll>{v1[i].first,v1[i].second});
        } else {
            sum[0].push_back(pair<pl, ll>{v1[i].first,v1[i].second+sum[0][i-1].second});
        }
    }
    rep(i,v1.size(), v1.size()+v4.size()){
        if(i==0){
            sum[0].push_back(pair<pl, ll>{v4[i].first,v4[i].second});
        } else {
            sum[0].push_back(pair<pl, ll>{v4[i].first,v4[i].second+sum[0][i-1].second});
        }
    }

    rep(i,0,v3.size()){
        if(i==0){
            sum[1].push_back(pair<pl, ll>{v3[i].first,v3[i].second});
        } else {
            sum[1].push_back(pair<pl, ll>{v3[i].first,v3[i].second+sum[0][i-1].second});
        }
    }
    rep(i,v4.size(), v3.size()+v2.size()){
        if(i==0){
            sum[1].push_back(pair<pl, ll>{v2[i].first,v2[i].second});
        } else {
            sum[1].push_back(pair<pl, ll>{v2[i].first,v2[i].second+sum[0][i-1].second});
        }
    }

    rep(i,0,Q){
        ll A, B;cin >> A >> B;
        A--;
        B--;
        pl pa = pt[A];
        pl pb = pt[B];

        ll sta,stb;
        if(pa.first == 0){
            if(pa.second > 0){
                sta = 1;
            } else {
                sta = 0;
            }
        } else if(pa.first > 0){
            sta = 0;
        } else {
            sta = 1;
        }
        if(pb.first == 0){
            if(pb.second > 0){
                stb = 1;
            } else {
                stb = 0;
            }
        } else if(pb.first > 0){
            stb = 0;
        } else {
            stb = 1;
        }

        if(sta == stb){
            
        }
    }
}