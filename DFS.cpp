#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int> adj[], int start, bool visited[]) {
    visited[start] = true;
    cout << start << " ";
    for(int i = 0; i < adj[start].size(); i++) {
        int next = adj[start][i];
        if(!visited[next]) {
            DFS(adj, next, visited);
        }
    }
}

int main() {
    int vertices, edges, start;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1];
    bool visited[vertices + 1] = {false};
    cout << "Enter the edges: ";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "DFS Traversal: ";
    DFS(adj, start, visited);
    cout << endl;
    return 0;
}
