//https://www.interviewbit.com/problems/cycle-in-directed-graph/
#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& vis) {
  vis[node] = 2;
  for (auto it : adj[node]) {
    if (!vis[it]) {
      if (dfs(it, adj, vis)) return true;
    } else if (vis[it] == 2) return true;
  }
  vis[node] = 1;
  return false;
}

int solve() {
  int A, numEdges;

  // Get the number of nodes (A) from the user
  cout << "Enter the number of nodes: ";
  cin >> A;

  // Get the number of edges from the user
  cout << "Enter the number of edges: ";
  cin >> numEdges;

  // Create adjacency list to represent the graph
  vector<vector<int>> adj(A + 1);

  // Get edge connections from the user
  for (int i = 0; i < numEdges; i++) {
    int start, end;
    cout << "Enter start and end node for edge " << i + 1 << ": ";
    cin >> start >> end;
    adj[start].push_back(end);
  }

  // Convert the adjacency list to the format used by dfs (optional)
  vector<int> adjList[A + 1];
  for (int i = 1; i <= A; ++i) {
    for (int neighbor : adj[i]) {
      adjList[i].push_back(neighbor);
    }
  }

  // Use vector<int>vis as before
  vector<int> vis(A + 1, 0);

  // Call dfs to check for cycles
  for (int i = 1; i <= A; i++) {
    if (dfs(i, adjList, vis)) return true;
  }

  return false;
}

int main() {
  if (solve()) {
    cout << "Cycle detected in the graph" << endl;
  } else {
    cout << "No cycle found in the graph" << endl;
  }
  return 0;
}
