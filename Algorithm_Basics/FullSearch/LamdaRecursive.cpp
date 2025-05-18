#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> a(N);
    auto dfs = [&](auto dfs, int i) -> void {
        if (i == N){
            for (int j = 0; j < N; j++){
                cout << a[j];
                if (j == N-1) cout << endl;
                else cout << " ";
            }
            return ;
        }
        for (int ai = 0; ai < A[i]; ai++){
            a[i] = ai;
            dfs(dfs,i+1);
        }
    };
    dfs(dfs,0);
}