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
struct trie {
  using ar = array<int, 26>;
  vector<ar> pos;
  ar def;
  int now_sz;
  long long ans;
  vector<int> cnt;
  trie() = default;
  trie(int len) {
    pos.reserve(len + 1);
    cnt.reserve(len + 1);
    def.fill(-1);
    now_sz = ans = 0;
    make_node();
  }
  int make_node() {
    pos.push_back(def);
    cnt.push_back(0);
    return now_sz++;
  }
  void add(string &s) {
    int now = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int d = s[i] - 'a';
      int &nx = pos[now][d];
      if(nx == -1)
        nx = make_node();
      now = nx;
      ans += cnt[now]++;
    }
  }
};

int main(){
    int N, L;cin >> N >> L;
    trie tr(100);
    rep(i,0,N){
        string S;
        cin >> S;
        tr.add(S);
    }

}