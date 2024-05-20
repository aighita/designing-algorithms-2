## Task 2 - Trains (Trenuri)

#### Overview
This program reads a directed acyclic graph (DAG) representing train routes from an input file, performs a topological sort on the graph, and then finds the longest path from a specified source to a destination node using DP.

#### Files
* trenuri.in: Input file containing the source, destination, number of edges (M), and the edges themselves.
* trenuri.out: Output file where the result (longest path length) is written.
* trenuri-log.out: Log file where the details of the unordered map and vectors are logged.

#### Functions

* printUnorderedMap: Prints the contents of an unordered map to the log file.
* topologicalSort: Performs a topological sort on the graph.
* topologicalSort2: An alternative topological sort that ensures the destination node is reached.
* printVector: Prints a vector of strings to the log file.
* find_max_path: Finds the maximum path length in the topologically sorted order.
* main: Reads input, performs topological sorting, finds the longest path, and writes the result.

#### Complexity
* Time Complexity: Topological Sort: O(V + E), where V is the number of vertices and E is the number of edges.
Finding the Longest Path: O(V + E), as it iterates through the nodes and edges once.
* Space Complexity: Topological Sort: O(V + E), for storing the in-degrees, the queue, and the sorted order.
Finding the Longest Path: O(V), for storing the dynamic programming (DP) table.
