#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

struct Edge {
    int to;
    long long weight;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; ++i) {
        int U, V;
        long long B;
        cin >> U >> V >> B;
        U--; V--; // converting to 0-based index
        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }

    // Dijkstra's algorithm
    vector<long long> dist(N, LLONG_MAX);
    dist[0] = A[0];
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({A[0], 0});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.to;
            long long weight = edge.weight;
            if (dist[u] + weight + A[v] < dist[v]) {
                dist[v] = dist[u] + weight + A[v];
                pq.push({dist[v], v});
            }
        }
    }

    // Output results
    for (int i = 1; i < N; ++i) {
        cout << dist[i] << (i == N-1 ? "\n" : " ");
    }

    return 0;
}
