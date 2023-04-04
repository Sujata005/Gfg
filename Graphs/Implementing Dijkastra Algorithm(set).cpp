#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       
        
        // Creating set
        set<pair<int,int>> s;
        
        // Distance vector of same size as the list and initializing it with 1e9
        vector<int> dist(V, 1e9);
        
        // Since the distance source node to itself is 0
        dist[S]=0;
        
        
        // for starting node
        s.insert({0,S});
        
      
        // Traversing the set
        while(!s.empty()){
            // pointing the it pointer to begining address of set
            auto it=*(s.begin());
            int distance=it.first;
            int node=it.second;
            s.erase(it);
            
            // Travelling adjacnt nodes
            for(auto it: adj[node]){
                // it is pair of distance that is edge weight and node
                int edgeWeight=it[1];
                int adjNode=it[0];
                // if the distance is lesser than the already stored in dist vector then replace it
                if(distance+edgeWeight<dist[adjNode]){
                    
                    // Erasing if the node is already been visited
                    if(dist[adjNode!=1e9])
                        s.erase({dist[adjNode],adjNode});
                    
                    dist[adjNode]=distance + edgeWeight;
                    
                    // pushing the new pair of shortest distance and node in the set
                    s.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};





int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
