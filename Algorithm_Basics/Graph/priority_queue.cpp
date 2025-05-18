#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq;

    // 値の追加
    pq.push(3);
    pq.push(5);
    
    // 最大値取得
    int x = pq.top(); // x = 5
    
    // 最大値削除
    pq.pop();

    //最小の場合
    priority_queue<int, vector<int>, greater<int>> pq;

    // 値の追加
    pq.push(3);
    pq.push(5);

    // 最小値取得
    int x = pq.top(); // x = 3

    // 最小値削除
    pq.pop();
}