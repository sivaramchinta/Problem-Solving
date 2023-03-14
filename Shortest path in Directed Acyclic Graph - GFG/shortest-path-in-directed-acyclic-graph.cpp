//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(int i,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>&s){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it.first]) solve(it.first,adj,vis,s) ;
        }
        s.push(i);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         // code here
        vector<pair<int,int>>adj[N];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>vis(N,0);
        stack<int>s;
        for(int i=0;i<N;i++){
            if(!vis[i]) solve(i,adj,vis,s);
        }
        vector<int>ans(N,INT_MAX);
        ans[0]=0;
        while(!s.empty()){
            int t=s.top();
            s.pop();
            for(auto it:adj[t]){
                int v=it.first;
                int u=it.second;
                if(ans[t]!=INT_MAX and ans[t]+u<ans[v]){
                    ans[v]=ans[t]+u;
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX) ans[i]=-1; 
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends