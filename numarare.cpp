#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007

using namespace std;

ifstream fin("numarare.inn");
ofstream fout("numarare.outt");

void topological_sort(int node, vector<vector<int>>& adj,
                    vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            topological_sort(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

vector<long long> count_paths(int N, vector<vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            topological_sort(i, adj, visited, st);
        }
    }

    vector<long long> dp(N + 1, 0);
    dp[1] = 1;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }

    return dp;
}

int main() {
    int N, M;
    fin >> N >> M;

    vector<vector<int>> adj1(N + 1), adj2(N + 1);

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        adj1[x].push_back(y);
    }

    for (int i = 0; i < M; ++i) {
        int x, y;
        fin >> x >> y;
        adj2[x].push_back(y);
    }

    vector<long long> dp1 = count_paths(N, adj1);
    vector<long long> dp2 = count_paths(N, adj2);

    long long common_paths = 0;
    for (int i = 1; i <= N; ++i) {
        if (dp1[i] == dp2[i] && dp1[i] > 0) {
            common_paths = (common_paths + dp1[i]) % MOD;
        }
    }

    // for (int i = 1; i <= N; ++i) {
    //     if (dp1[i] == dp2[i] && dp1[i] > 0) {
    //         common_paths = (common_paths + dp1[i]) % MOD;
    //     }
    // }

    fout << common_paths << endl;

    for (int i = 1; i <= N; ++i) {
        fout << dp1[i] <<  " " << dp2[i] << endl;
    }

    return 0;
}
