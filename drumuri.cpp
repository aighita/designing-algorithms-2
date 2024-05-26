#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <tuple>
#include <climits>

using namespace std;

typedef pair<int, long long> pli;
#define INF (1LL << 60)

vector<long long> dijkstra(int start, int n, const vector<vector<pli>>& adj) {
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int n, m;
    fin >> n >> m;

    vector<vector<pli>> adj(n);
    vector<vector<pli>> adj_rev(n);
    vector<tuple<int, int, long long>> edges;

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        fin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
        adj_rev[b].emplace_back(a, c);
        edges.emplace_back(a, b, c);
    }

    int x, y, z;
    fin >> x >> y >> z;
    x--; y--; z--;

    vector<long long> dist_x = dijkstra(x, n, adj);
    vector<long long> dist_y = dijkstra(y, n, adj);
    vector<long long> dist_z = dijkstra(z, n, adj_rev);

    long long min_cost = INF;

    for (const auto& edge : edges) {
        int a, b;
        long long c;
        tie(a, b, c) = edge;

        if (dist_x[a] < INF && dist_z[a] < INF && dist_y[a]) {
            long long total_cost = dist_x[a] + dist_z[a] + dist_y[a];
            min_cost = min(min_cost, total_cost);
        }
    }

    fout << min_cost << "\n";

    return 0;
}
