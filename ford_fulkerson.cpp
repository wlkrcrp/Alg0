#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 6  // Number of vertices in the graph

// Function to execute a DFS on the residual graph and find if there is a path from source to sink.
// It also fills the path found in the parent[] array.
bool dfs(int residualGraph[][V], int source, int sink, int parent[]) {
    vector<bool> visited(V, false);
    vector<int> stack;
    stack.push_back(source);
    visited[source] = true;
    parent[source] = -1;  // -1 indicates the start of the path (no parent)

    while (!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {  // Check for unvisited vertex with residual capacity > 0
                stack.push_back(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink)
                    return true;  // Path to sink found
            }
        }
    }
    return false;  // No path to sink found
}

// Function to implement the Ford-Fulkerson algorithm for finding the maximum flow from source to sink.
int fordFulkerson(int graph[V][V], int source, int sink) {
    int u, v;

    // Create a residual graph and fill the residual graph with given capacities in the original graph as residual capacities
    int residualGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            residualGraph[u][v] = graph[u][v];

    int parent[V];  // Array to store the path
    int max_flow = 0;  // There is initially no flow

    // Augment the flow while there is a path from source to sink
    while (dfs(residualGraph, source, sink, parent)) {
        // Find the minimum capacity in the path filled by DFS
        int path_flow = INT_MAX;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, residualGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges along the path
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= path_flow;
            residualGraph[v][u] += path_flow;
        }

        max_flow += path_flow;  // Add path flow to the overall flow
    }

    return max_flow;  // Return the overall flow
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5) << endl;
    return 0;
}