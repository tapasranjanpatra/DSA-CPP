#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<int> adj[], int start, int vertices) {
    bool visited[vertices + 1];
    for(int i = 0; i <= vertices; i++) {
        visited[i] = false;
    }
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i];
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int vertices, edges, start;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;
    vector<int> adj[vertices + 1];
    cout << "Enter the edges: ";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "BFS Traversal: ";
    BFS(adj, start, vertices);
    cout << endl;
    return 0;
}
