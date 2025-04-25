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
bool chmax(T &a, const T& b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
//a,bのうち最小のものをaに入れる(aがbに置き換わるときはtrueを返す)
template <typename T>
bool chmin(T &a, const T& b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
vector<long long> makediv(long long n) {
    vector<long long> ld, ud;
    for (long long i = 1; i * i*i <= 4*n+1; i++) {
      if (n % i == 0) {
        ld.push_back(i);
        if (n / i != i) {
          ud.push_back(n / i);
        }
      }
    }
    reverse(ud.begin(), ud.end());
    ld.insert(ld.end(), ud.begin(), ud.end());
    return ld;
  }
  
int main(){
    ll N;cin >> N;
    vl yak = makediv(N);

    
    rep(i,0,yak.size()){
        ll D = N/yak[i]*4-yak[i]*yak[i];
        if(D%3!=0){continue;}
        ll rD = sqrt(D/3);
        if(rD*rD!=D/3){continue;}
        ll rDY =3*rD-3*yak[i];
        if(rDY>0&&rDY%6==0){
            cout << yak[i]+rDY/6 << " " << rDY/6 << "\n";
            return 0;
        }

    }
    
    cout << -1 << "\n";
}