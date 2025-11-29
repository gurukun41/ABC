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

#include <iostream>
#include <array>

class UnionFind
{
public:
	std::array<pair<int,bool>, 200009> par; //各要素の親ノードを管理する配列(黒かどうかも)
	std::array<pair<int,int>, 200009> siz; //頂点xを根とするグループの要素数を管理する配列(黒の数も)

	UnionFind()
	{
		par.fill({-1,0}); //最初は親ノードを持たないので-1で初期化
		siz.fill({1,0}); //最初は各要素がそれぞれ異なるグループに属しているので1で初期化
	}

    //頂点xの根を求める
	int root(int x)
	{
		while (par.at(x).first != -1)
		{
			x = par.at(x).first; //親ノードがなくなるまで探索する
		}

		return x;
	}

    //要素uとvのグループを統合する
	void unite(int u, int v)
	{
		int RootU = root(u);
		int RootV = root(v);

		if (RootU == RootV)
		{
			return;
		}

        //要素数が多いグループの根を統合後のグループの根にする
		if (siz.at(RootU) < siz.at(RootV))
		{
			par.at(RootU).first = RootV;
			siz.at(RootV).first = siz.at(RootU).first + siz.at(RootV).first;
            siz.at(RootV).second = siz.at(RootU).second + siz.at(RootV).second;
		}
		else
		{
			par.at(RootV).first = RootU;
			siz.at(RootU).first = siz.at(RootU).first + siz.at(RootV).first;
			siz.at(RootU).second = siz.at(RootU).second + siz.at(RootV).second;
		}
	}

    //要素uとvが同じグループに属するかを判定する
	bool same(int u, int v)
	{
		if (root(u) == root(v))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

    //要素xのグループのメンバーの数を求める
	int count_member(int x)
	{
		int RootX = root(x);
		return siz.at(RootX).first;
	}

    int count_black(int x){
		int RootX = root(x);
		return siz.at(RootX).second;       
    }
    void change_black(int x, int del){
        int RootX = root(x);
		siz.at(RootX).second+=del; 
    }
};


int main(){
    ll N,Q;cin >> N >> Q;
    UnionFind uf;
    vector<string> ans;
    rep(_,0,Q){
        ll q;cin >> q;
        if(q == 1){
            ll u,v;cin >> u >> v;
            uf.unite(u,v);
        }
        else if(q == 2){
            ll v;cin >> v;
            if(uf.par[v].second){
                uf.par[v].second = 0;
                uf.change_black(v,-1);
            }
            else{
                uf.par[v].second = 1;
                uf.change_black(v,1);                
            }
        }
        else{
            ll v;cin >>v;
            int num = uf.count_black(v);
            if(num > 0){
                ans.push_back("Yes\n"); 
            }
            else{
                ans.push_back("No\n");
            }
        }
    }
    for(string out:ans){
        cout << out;
    }

}