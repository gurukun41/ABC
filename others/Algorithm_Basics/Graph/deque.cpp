#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;

    // 末尾に追加
    dq.push_back(1); // dq = {1}
    dq.push_back(2); // dq = {1, 2}

    // 先頭に追加
    dq.push_front(3); // dq = {3, 1, 2}
    dq.push_front(4); // dq = {4, 3, 1, 2}
    dq.push_front(5); // dq = {5, 4, 3, 1, 2}

    // 先頭を削除
    dq.pop_front(); // dq = {4, 3, 1, 2}

    // 先頭要素取得
    int x = dq.front(); // x = 4

    // 末尾を削除
    dq.pop_back(); // dq = {4, 3, 1}
    dq.pop_back(); // dq = {4, 3}

    // 末尾要素取得
    int y = dq.back(); // y = 3
}