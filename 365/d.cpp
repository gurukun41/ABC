#include <iostream>
#include <array>
#include <algorithm>
int main() {
    using namespace std;
    unsigned N;
    cin >> N;
    string S;
    cin >> S;
    array<unsigned, 3> dp{};
    auto&& [rock, scissors, paper]{dp};
    for(const auto c : S){
        // 直前に出していなかった手を出すことができる
        dp = {max(scissors, paper), max(rock, paper), max(rock, scissors)};
        // 負ける手を出すことはできない = 勝ち数の最大値を 0 にする
        // 勝つ手を出したら最大値 +1
        cout << dp[0] << dp[1] << dp[2] << endl;
        cout << c << endl;
        if (c == 'R') {
            scissors = 0;
            ++paper;
        } else if (c == 'S') {
            paper = 0;
            ++rock;
        } else if (c == 'P') {
            rock = 0;
            ++scissors;
        }
        cout << dp[0] << dp[1] << dp[2] << endl;
    }
    cout << ranges::max(dp) << endl;
    return 0;
}