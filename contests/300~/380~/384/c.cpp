#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using vl = vector<ll>;//long long型の一次元
using vvl = vector<vl>;//long long型の二次元配列
using vvvl = vector<vvl>;//long long型の三次元配列
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define bte(v) v.begin(), v.end()
template <typename T> 
T input(){
    T x;
    cin >> x;
    return x;
}
template <typename T> 
int input(ll &x){
    T y;
    cin >> y;
    x = y;
    return 0;
}
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main(){
    ll a,b,c,d,e; cin >> a >> b >> c >> d >> e;
    vector<pair<ll,string>> score(0);
    score.push_back({a, "A" });
    score.push_back({b, "B" });
    score.push_back({c, "C" });
    score.push_back({d, "D" });
    score.push_back({e, "E" });
    score.push_back({a+b, "AB" });
    score.push_back({a+c,"AC" });
    score.push_back({a+d,"AD" });
    score.push_back({a+e,"AE" });
    score.push_back({b+c,"BC" });
    score.push_back({b+d,"BD" });
    score.push_back({b+e,"BE" });
    score.push_back({c+d,"CD" });
    score.push_back({c+e,"CE" });
    score.push_back({d+e,"DE" });
    score.push_back({a+b+c,"ABC" });
    score.push_back({a+b+d,"ABD" });
    score.push_back({a+b+e,"ABE" });
    score.push_back({a+c+d,"ACD" });
    score.push_back({a+c+e,"ACE" });
    score.push_back({a+d+e,"ADE" });
    score.push_back({b+c+d,"BCD" });
    score.push_back({b+c+e,"BCE" });
    score.push_back({b+d+e,"BDE" });
    score.push_back({c+d+e,"CDE" });
    score.push_back({a+b+c+d,"ABCD" });
    score.push_back({a+b+c+e,"ABCE" });
    score.push_back({a+b+d+e,"ABDE" });
    score.push_back({a+c+d+e,"ACDE" });
    score.push_back({b+c+d+e,"BCDE" });
    score.push_back({a+b+c+d+e,"ABCDE" });
    sort(score.rbegin(), score.rend());
    ll same = -1;
    ll ini = 0;
    rep(i,0,31){

      if(score[i].first != same){
        if(i - ini !=1){
          vector<pair<string, ll>> vp;
          rep(j,0,i-ini){
            vp.push_back({score[ini+j].second, score[ini+j].first});
          }
          sort(vp.begin(),vp.end());
          rep(j,0,i-ini){
            pair<ll,string> p;
            p = make_pair(vp[j].second,vp[j].first);
            score[ini+j] = p;
          }
          
        }
        ini = i;
        same = score[i].first;
      }
      
      if(i==30&&ini!=30){
        vector<pair<string, ll>> vp;
          rep(j,0,i-ini+1){
            vp.push_back({score[ini+j].second, score[ini+j].first});
          }
          sort(vp.begin(),vp.end());
          rep(j,0,i-ini+1){
            pair<ll,string> p;
            p = make_pair(vp[j].second,vp[j].first);
            score[ini+j] = p;
          }
      }
      same = score[i].first;
      

    }
    for(auto v: score){
      cout << v.second << "\n";
    }
 }