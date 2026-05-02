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
    ll T;cin >> T;
    vl ans(T,0);
    rep(_,0,T){
        string A, B;cin >> A >> B;
        string NA = "", NB = "";
        ll c1 = 0;
        ll c2 = 0;
        ll c3 = 0;

        rep(i,0,A.size()){
            if(c1 == 0){
                if(A[i] != '('){
                    NA+=A[i];
                } else {
                    c1++;
                    if(i == A.size()-1){
                        NA+=A[i];
                    }
                }
            } else {
                if(c2 == 0){
                    if(A[i] == 'x'){
                        c2++;
                        if(i == A.size()-1){
                            rep(j,i-c1-c2+1,i+1){
                                NA += A[j];
                            }
                        }
                    } else if(A[i] == '('){
                        c1++;
                        if(i == A.size()-1){
                            rep(j,i-c1+1,i+1){
                                NA += A[j];
                            }
                        }                        
                    } else {
                        rep(j,i-c1,i+1){
                            NA += A[j];
                        }     
                        c1=0;                  
                    }
                } else if(c2 == 1){// xxであるか
                    if(A[i] != 'x'){
                        rep(j,i-c1-c2,i){
                            NA += A[j];
                        }
                        i--;
                        c1=0;c2=0;
                    }else{
                        c2++;
                        if(i == A.size()-1){
                            rep(j,i-c1-c2+1,i+1){
                                NA += A[j];
                            }
                        }  
                    }
                } else if(c2==2){
                    if(A[i] == ')'){
                        c3++;
                        if(c1 ==c3){
                            c1=0;c2=0;c3=0;
                            NA+="xx";
                        } else if(i == A.size()-1){
                            rep(j,i-c1-c2-c3+1,i-c2-2*c3+1){
                                NA+=A[j];
                            }
                            NA+="xx";
                        }
                    } else {
                        i--;
                        rep(j,i-c1-c2-c3+1,i-c2-2*c3+1){
                            NA+=A[j];
                        }
                        NA+="xx";
                        c1=0;c2=0;c3=0;
                    }
                }
            }
        }
        c1=0;c2=0;c3=0;
        rep(i,0,B.size()){
            if(c1 == 0){
                if(B[i] != '('){
                    NB+=B[i];
                } else {
                    c1++;
                    if(i == B.size()-1){
                        NB+=B[i];
                    }
                }
            } else {
                if(c2 == 0){
                    if(B[i] == 'x'){
                        c2++;
                        if(i == B.size()-1){
                            rep(j,i-c1-c2+1,i+1){
                                NB += B[j];
                            }
                        }
                    } else if(B[i] == '('){
                        c1++;
                        if(i == B.size()-1){
                            rep(j,i-c1+1,i+1){
                                NB += B[j];
                            }
                        }
                    } else {
                        rep(j,i-c1,i+1){
                            NB += B[j];
                        }     
                        c1=0;                  
                    }
                } else if(c2 == 1){// xxであるか
                    if(B[i] != 'x'){
                        rep(j,i-c1-c2,i){
                            NB += B[j];
                        }
                        i--;
                        c1=0;c2=0;
                    }else{
                        c2++;
                        if(i == B.size()-1){
                            rep(j,i-c1-c2+1,i+1){
                                NB += B[j];
                            }
                        }  
                    }
                } else if(c2==2){
                    if(B[i] == ')'){
                        c3++;
                        if(c1 ==c3){
                            c1=0;c2=0;c3=0;
                            NB+="xx";
                        } else if(i == B.size()-1){
                            rep(j,i-c1-c2-c3+1,i-c2-2*c3+1){
                                NB+=B[j];
                            }
                            NB+="xx";
                        }
                    } else {
                        i--;
                        rep(j,i-c1-c2-c3+1,i-c2-2*c3+1){
                            NB+=B[j];
                        }
                        NB+="xx";
                        c1=0;c2=0;c3=0;
                    }
                }
            }
        }
        if(NA == NB){
            ans[_] = 1;
        }
    }
    rep(i,0,T){
        yn(ans[i]);
    }
}