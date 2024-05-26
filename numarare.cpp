#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <utility>

#define MOD 1000000007

using namespace std;

ifstream fin("numarare.in");
ofstream fout("numarare.out");

int N, M;

vector<vector<int>> findCommonEdges(vector<vector<int>> &graph1_adj,
                                    vector<vector<int>> &graph2_adj,
                                    int N) {
    vector<vector<bool>> graph1_edges(N + 1, vector<bool>(N + 1, false));
    vector<vector<int>> commonGraph(N + 1);

    for (int u = 1; u <= N; ++u) {
        for (int v : graph1_adj[u]) {
            graph1_edges[u][v] = true;
        }
    }

    for (int u = 1; u <= N; ++u) {
        for (int v : graph2_adj[u]) {
            if (graph1_edges[u][v]) {
                commonGraph[u].push_back(v);
            }
        }
    }

    return commonGraph;
}

void printGraph(vector<vector<int>>& graph) {
    int N = graph.size();
    for (int u = 1; u < N; ++u) {
        for (int v : graph[u]) {
            cout << u << " " << v << endl;
        }
    }
}

int find_all_paths_1_to_N(vector<vector<int>>& graph) {
    vector<int> DP(N + 1);

    DP[1] = 1;
    for (int u = 1; u < N; ++u) {
        for (int v : graph[u]) {
            DP[v] += DP[u];
            DP[v] %= MOD;
        }
    }

    return DP[N];
}

int main() {
    fin >> N >> M;

    vector<vector <int>> graph1_adj(N + 1);
    vector<vector <int>> graph2_adj(N + 1);

    int x, y;
    for (int i = 1; i <= M; i++) {
        fin >> x >> y;
        graph1_adj[x].push_back(y);
    }

    for (int i = 1; i <= M; i++) {
        fin >> x >> y;
        graph2_adj[x].push_back(y);
    }

    vector<vector<int>> common_graph = findCommonEdges(graph1_adj,
                                                        graph2_adj, N);
    // printGraph(common_graph);

    int paths = find_all_paths_1_to_N(common_graph);
    fout << paths << endl;

    return 0;
}
