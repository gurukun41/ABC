#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
int main() {
    ll N,M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> G(N,vector<pair<ll,ll>>());
    rep(i,0,M){
        ll u,v,w;
        cin >> u >> v >> w;
        u --;
        v --;
        pair<ll,ll> p1(v,w);
        G[u].push_back(p1);
        pair<ll,ll>p2(u,-w);
        G[v].push_back(p2);
    }
    vector<bool> visited(N,0);
    vector<ll> ans(N,0);
    rep(i,0,N){
        if(visited[i]){
            continue;
        }
        vector<ll> st(1,i);
        visited[i] = 1;
        while(st.size()>0){
            ll u = st.back();
            st.pop_back();
            for(pair<ll,ll> p : G[u]){
                ll v = p.first,w = p.second;
                if(!visited[v]){
                    visited[v] = 1;
                    ans[v] = ans[u] + w;
                    st.push_back(v);
                }
            }
        }
    }
    rep(i,0,N){
        cout << ans[i] << " ";
    }
}