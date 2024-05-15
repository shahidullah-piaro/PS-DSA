//https://www.interviewbit.com/problems/path-in-directed-graph/
#include <bits/stdc++.h>

using namespace std;

bool isfoundDFS(vector<vector<int>> &adj, int A, int source, vector<bool> &vis){

    if(source == A) return 1;



    for(int child:adj[source]){

        if(vis[child]) continue;

        vis[child] = true;

        if(isfoundDFS(adj, A, child, vis)) return 1;

    }

    return 0;

}

int solve(int A, vector<vector<int>>& B) {

    vector<vector<int>> adj; for(int i=0;i<A;i++) adj.push_back({});

    for(int i=0;i<B.size();i++){

        int u = B[i][0]-1;

        int v = B[i][1]-1;

        adj[u].push_back(v);

    }

    // adj list is ready



    A--;

    vector<bool> vis(A+1, false);



    for(int i=0;i<A;i++){

        vis[i] = true;

        if(isfoundDFS(adj, A, i, vis)) return 1;

    }

    return 0;
}

int main() {
  int num_nodes, num_edges;

  cout << "Enter the number of nodes: ";
  cin >> num_nodes;

  cout << "Enter the number of edges: ";
  cin >> num_edges;

  vector<vector<int>> edges(num_edges, vector<int>(2));

  cout << "Enter the edges (start node, end node):\n";
  for (int i = 0; i < num_edges; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }


  if (solve(num_nodes, edges)) {
    cout << "There is a path in the graph." << endl;
  } else {
    cout << "There is no path in the graph." << endl;
  }

  return 0;
}
