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

// 無限大の値
const long long INF = 1LL << 60;

int main(){
    int T;cin >> T;
    rep(i,0,T){
        int N;cin >> N;
        vl A(N);
        vector<pair<ll,ll>> B(N);
        int check;
        int cpn = 0;
        int cnn = 0;
        bool checking = true;
        rep(j,0,N){
            cin >> A[j];
            if(j==0){
                check = A[j];
                if(A[j] < 0){
                    cnn++;
                }
                else{
                    cpn++;
                }
            }
            else if(checking){
                if(A[j] == check || A[j] == -check){
                    if(A[j] < 0){
                        cnn++;
                    }
                    else{
                        cpn++;
                    }
                }
                else{
                    checking = false;
                }
            }


            if(A[j] < 0){
                B[j] = make_pair(-A[j],j);
            }
            else{
                B[j] = make_pair(A[j],j);
            }
        }
        if(checking){
            if(cnn == cpn || cnn == cpn+1 || cpn == cnn+1||cnn ==0||cpn==0){
                cout << "Yes" << "\n";
                continue;
            }
            else{
                cout << "No" << "\n";
                continue;
            }
        }

        sort(all(B));
        bool no = false;
        rep(j,0,N-2){
            if(A[B[j+2].second]*A[B[j].second] != A[B[j+1].second]*A[B[j+1].second]){
                cout << "No" << "\n";
                no = true;
                break;
            }
        }
        if(!no){
            cout << "Yes" << "\n";
        }

    }
}