#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    void dfs(int node,vector<int> &vis, vector<vector<int>> &adj, stack<int> &s){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,s);
            }
        }
        s.push(node);
    }
    void dfs1(int node,vector<int> &vis, vector<int>adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs1(it,vis,adj);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        //code here
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,s);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                //i->it & it->i
                adjT[it].push_back(i);      //Reversing graph
            }
        }
        int scc=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!vis[node]){
                scc++;
                dfs1(node,vis,adjT);
            }
        }
        return scc;
    }
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
