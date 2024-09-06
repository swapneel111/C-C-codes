#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> vis(V, 0); // visited array initialized to 0
        queue<int> q;
        
        // Start BFS from node 0
        vis[0] = 1;
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            // Traverse all adjacent nodes
            for (auto it : adj[nod
			e]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(const vector<int>& ans) {
    for (int v : ans) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    vector<int> adj[6]; // Graph with 6 vertices (0 to 5)
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
    
    Solution obj;
    vector<int> ans = obj.bfsOfGraph(5, adj); // 5 vertices
    printAns(ans);

    return 0;
}

