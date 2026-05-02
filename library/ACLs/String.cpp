#include <bits/stdc++.h>
#include <atcoder/string>
using namespace std;
using ll = long long;

/*
ACL String

1. Z Algorithm
z[i] = S と S[i:] の最長共通接頭辞の長さ

パターン検索:
T = pattern + '$' + text として z を見る。
*/
void z_algorithm_example() {
    string s = "ababa";
    vector<int> z = atcoder::z_algorithm(s);
}

/*
2. Suffix Array / LCP Array
suffix_array(s): suffix の開始位置を辞書順に並べる
lcp_array(s, sa): 隣り合う suffix の LCP 長

文字列の辞書順、異なる部分文字列数、最長共通部分文字列などで使う。
*/
void suffix_array_example() {
    string s = "banana";
    vector<int> sa = atcoder::suffix_array(s);
    vector<int> lcp = atcoder::lcp_array(s, sa);
}
