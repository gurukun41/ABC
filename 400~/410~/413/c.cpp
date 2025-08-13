#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;                                  //long long型の一次元
using vvl = vector<vl>;                                 //long long型の二次元配列
using vvvl = vector<vvl>;                               //long long型の三次元配列
using vi = vector<int>;                                 //int型の一次元
using vvi = vector<vi>;                                 //int型の二次元配列
using vvvi = vector<vvi>;                               //int型の三次元配列
#define rep(i,a,b) for(int i = (a); i < (int)(b); i++)  //for文の短縮
#define all(v) v.begin(), v.end()                       //all(v)でvの始まりと終わりのイテレーター

//入力を受け取る
template <typename T> 
T input(){
    T x;
    cin >> x;
    return x;
}

//a,bのうち最大のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmax(T &a, const T& b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

//a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
inline bool chmin(T &a, const T& b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

//素数判定
bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

ll check(ll tar, vl &s){
    ll l = -1, r = s.size();
    while(r-l > 1){
        ll m = (r+l)/2;
        if(s[m] >= tar){
            r = m;
        }
        else {
            l = m;
        }
    }

    return r;
}

int main(){
    ll Q; cin >> Q;
    vector<pair<ll,ll>> A;
    vector<ll> sum;
    ll p = 0;
    ll last = 0;
    ll delnum = 0;

    rep(j,0,Q){
        int q;cin >> q;
        if(q==1){
            ll c,x;cin >>c >>x;
            A.push_back({x,c});
            if(last>0){
                sum.push_back(sum[last-1] + c);
            }
            else{
                sum.push_back(c);
            }
            last++;
        }
        else{
            ll k;cin >>k;
            ll out = 0;
            ll t = check(k+delnum,sum);
            ll d = 0;
            for(ll i = p;i <= t; i++){
                if(A[i].second > k-d){
                    A[i].second -= (k-d);
                    out += A[i].first*(k-d);
                    break;
                }
                else{
                    out += A[i].first*A[i].second;
                    d += A[i].second;
                    A[i].second = 0;
                    p++;
                }
            }
            p = t;
            /*while(true){
                ll num = A[p].second;
                if(num > k){
                    A[p].second -= k;
                    out += A[p].first*k;
                    break;
                }
                else{
                    A[p].second = 0;
                    out += A[p].first*num;
                    k-=num;
                    p++;
                }
            }*/
            cout << out << "\n";
            delnum += k;
        }
    }
}