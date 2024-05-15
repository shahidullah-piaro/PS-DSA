//https://leetcode.com/problems/course-schedule-ii/
#include <bits/stdc++.h>

using namespace std;

//7.reverse the topological order to get a answer
        void reverseVector(vector<int>& vec) {
          int left = 0;
          int right = vec.size() - 1;

          while (left < right) {
            // Swap elements at left and right indices
            swap(vec[left], vec[right]);
            left++;
            right--;
          }
        }

vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        //1.create the adjacendy list
        vector<int> adj[n];

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        //2.find indegree of each node
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        //3.find indegree 0 node
        queue<int> q;
        //find number whose indegree is zero
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //4.apply the bfs or khans algo
        vector<int> topo_order;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_order.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
        //5.if any node with 0 degree add that into queue
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        //6,check condition if all elements are added if not there must be a cycle in a graph rreturn the empty array
        if(topo_order.size() != n) return {};

        //7.reverse the topological order to get a answer
        reverseVector(topo_order);
        return topo_order;
    }

int main() {
    int n, m;  // Number of nodes and edges

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of prerequisites (edges): ";
    cin >> m;

    vector<vector<int>> prerequisites(m, vector<int>(2));  // Input format: {u, v}
    cout << "Enter the prerequisites (u -> v) one by one:\n";
    for (int i = 0; i < m; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    vector<int> topo_order = findOrder(n, prerequisites);



    if (topo_order.empty()) {
        cout << "The graph has a cycle. No valid topological order exists." << endl;
    } else {
        cout << "Topological Order: ";
        for (int node : topo_order) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

