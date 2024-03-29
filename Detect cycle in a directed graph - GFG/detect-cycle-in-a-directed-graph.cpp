//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int c,vector<int>adj[],vector<int>&v,vector<int>&v2){
        if(v[c]==0)
        {
            v[c]=1;
            v2[c]=1;
            for(auto it:adj[c]){
                if(!v[it]){
                    if(dfs(it,adj,v,v2)){
                      return true;
                    
                    } 
                }
                else if(v2[it]==1){
                        return true;
            }
        }
        }
        v2[c]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>v(V,0);
        vector<int>v2(V,0);
        for(int i=0;i<V;i++){
            if(!v[i]){
                if(dfs(i,adj,v,v2)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends