#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

#define MAX_NODES 1000005

using namespace std;

ifstream fin("scandal.in");
ofstream fout("scandal.out");

int num_vars, num_clauses;
vector<int> graph[MAX_NODES];
vector<int> transpose_graph[MAX_NODES];
int order[MAX_NODES], num_scc = 0;
bool visited[MAX_NODES];
bool solution[MAX_NODES];

inline int get_complement(int var) {
    return (var > num_vars) ? (var - num_vars) : (var + num_vars);
}

void read_input() {
    fin >> num_vars >> num_clauses;
    int var1, var2, type;
    while (num_clauses--) {
        fin >> var1 >> var2 >> type;
        var1 += num_vars * ((type & 2) != 0);
        var2 += num_vars * (type & 1);
        graph[get_complement(var1)].push_back(var2);
        transpose_graph[var2].push_back(get_complement(var1));
        graph[get_complement(var2)].push_back(var1);
        transpose_graph[var1].push_back(get_complement(var2));
    }
    fin.close();
}

void depth_first_search(int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (int adj : graph[node])
        if (!visited[adj])
            depth_first_search(adj);
    order[++num_scc] = node;
}

void depth_first_search_transpose(int node) {
    if (visited[node]) return;
    visited[node] = true;
    solution[get_complement(node)] = true;
    for (int adj : transpose_graph[node])
        if (!visited[adj])
            depth_first_search_transpose(adj);
}

void solve() {
    for (int i = 1; i <= 2 * num_vars; ++i)
        if (!visited[i])
            depth_first_search(i);

    memset(visited, 0, sizeof(visited));
    for (int i = 2 * num_vars; i >= 1; --i)
        if (!visited[order[i]] && !visited[get_complement(order[i])])
            depth_first_search_transpose(order[i]);

    int sol_count = 0;
    for (int i = 1; i <= num_vars; ++i)
        if (solution[i])
            sol_count++;
    fout << sol_count << '\n';
    for (int i = 1; i <= num_vars; ++i)
        if (solution[i])
            fout << i << '\n';
    fout.close();
}

int main() {
    read_input();
    solve();
    return 0;
}
