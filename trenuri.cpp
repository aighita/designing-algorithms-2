#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <climits>

#define INF INT_MAX

using namespace std;

ifstream fin("trenuri.in");
ofstream fout("trenuri.out");

ofstream flog("trenuri-log.out");

string source, destination;
int M;

unordered_map<string, vector<string>> train_map;

void printUnorderedMap(const unordered_map<string, vector<string>>& umap) {
    for (const auto& pair : umap) {
        flog << pair.first << " : ";
        for (const auto& str : pair.second) {
            flog << str << " ";
        }
        flog << endl;
    }
    flog << endl;
}

vector<string> topologicalSort
            (const unordered_map<string, vector<string>>& graph) {
    unordered_map<string, int> in_degree;
    queue<string> zero_in_degree_queue;
    vector<string> sorted_order;

    for (const auto& pair : graph) {
        in_degree[pair.first] = 0;
    }

    for (const auto& pair : graph) {
        for (const auto& neighbor : pair.second) {
            if (in_degree.find(neighbor) == in_degree.end()) {
                in_degree[neighbor] = 0;
            }
            in_degree[neighbor]++;
        }
    }

    for (const auto& pair : in_degree) {
        if (pair.second == 0) {
            zero_in_degree_queue.push(pair.first);
        }
    }

    while (!zero_in_degree_queue.empty()) {
        string current = zero_in_degree_queue.front();
        zero_in_degree_queue.pop();
        sorted_order.push_back(current);

        if (graph.find(current) != graph.end()) {
            for (const auto& neighbor : graph.at(current)) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    zero_in_degree_queue.push(neighbor);
                }
            }
        }
    }

    // Not necessary since we use DAGs
    // if (sorted_order.size() != in_degree.size()) {
    //     throw runtime_error("Graph has a cycle,
    //              topological sort not possible.");
    // }

    return sorted_order;
}

vector<string> topologicalSort2(const unordered_map<string,
                vector<string>>& graph, const string& dest) {
    unordered_map<string, int> in_degree;
    queue<string> zero_in_degree_queue;
    vector<string> sorted_order;
    unordered_set<string> visited;

    for (const auto& pair : graph) {
        if (in_degree.find(pair.first) == in_degree.end()) {
            in_degree[pair.first] = 0;
        }
        for (const auto& neighbor : pair.second) {
            if (in_degree.find(neighbor) == in_degree.end()) {
                in_degree[neighbor] = 0;
            }
            in_degree[neighbor]++;
        }
    }

    for (const auto& pair : in_degree) {
        if (pair.second == 0) {
            zero_in_degree_queue.push(pair.first);
        }
    }

    while (!zero_in_degree_queue.empty()) {
        string current = zero_in_degree_queue.front();
        zero_in_degree_queue.pop();
        sorted_order.push_back(current);
        visited.insert(current);

        if (current == dest) {
            continue;
        }

        if (graph.find(current) != graph.end()) {
            for (const auto& neighbor : graph.at(current)) {
                if (--in_degree[neighbor] == 0 &&
                    visited.find(neighbor) == visited.end()) {
                    zero_in_degree_queue.push(neighbor);
                }
            }
        }
    }

    if (find(sorted_order.begin(),
        sorted_order.end(), dest) == sorted_order.end()) {
        cerr << "Destination not reachable from the source." << endl;
        return {};
    }

    return sorted_order;
}

void printVector(const vector<string>& vec) {
    for (const auto& str : vec) {
        flog << str << "\n";
    }
    flog << endl << endl;
}

int find_max_path(const vector<string>& tpsort) {
        unordered_map<string, int> dp;
        for (const auto& node : tpsort) {
            dp[node] = -INF;
        }

        dp[source] = 0;

        for (const auto& node : tpsort) {
            if (dp[node] != -INF) {
                for (const auto& neighbor : train_map[node]) {
                    if (dp[node] + 1 > dp[neighbor]) {
                        dp[neighbor] = dp[node] + 1;
                    }
                }
            }
        }

        return dp[destination] == -INF ? -1 : dp[destination];
    }

int main() {
    fin >> source >> destination >> M;

    for (int i = 0; i < M; i++) {
        string src, dest;
        fin >> src >> dest;
        train_map[src].push_back(dest);
    }

    printUnorderedMap(train_map);

    vector<string> sorted = topologicalSort(train_map);

    printVector(sorted);

    fout << find_max_path(sorted) + 1;

    return 0;
}
