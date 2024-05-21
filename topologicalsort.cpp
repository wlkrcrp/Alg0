#include <bits/stdc++.h>
using namespace std;
#define V 4

void topologicalSortUtil(int u,int adj[][V],
                         vector<bool>& visited,
                         stack<int>& Stack)
{
    visited[u] = true;

    for (int v=0;v<V;v++) {
        if (!visited[v] && adj[u][v]>0)
            topologicalSortUtil(v, adj, visited, Stack);
    }
    Stack.push(u);
}

void topologicalSort(int adj[][V])
{
    stack<int> stack; 
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++) {
        if (!visited[u])
            topologicalSortUtil(u, adj, visited, stack);
    }
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main()
{
    int adj[V][V]={
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,0},
        {0,1,1,0}
    };

    cout << "Topological sorting of the graph: ";
    topologicalSort(adj);

    return 0;
}