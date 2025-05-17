#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // ここから下を関数に切り分ける
            // print (i*j)th of fibonatti sequence
            int first = 1, second = 1;
            for (int k = 0; k < i*j; k++) {
                int next = first + second;
                first = second;
                second = next;
            }
            // ここから上を関数に切り分ける
            cout << second << " ";
        }
        cout << endl;
    }
}