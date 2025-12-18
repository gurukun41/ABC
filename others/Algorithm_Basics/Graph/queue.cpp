#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;

    // 要素の追加
    q.push(1); // q = {1}
    q.push(2); // q = {1, 2}

    // 先頭の取得
    int x = q.front(); // x = 1

    // 要素の削除
    q.pop(); // q = {2}
}