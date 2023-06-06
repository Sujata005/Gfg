class Solution {
    bool bfs(int start, int V, vector<int> adj[], int color[]){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // if adjacent node not colored give opposite color
            for(auto it:adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
        }
        return true;
    }
    
    bool dfs(int node, int col,  vector<int> adj[], int color[]){
        color[node]=col;
        //traverse adjacent node
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,adj,color)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	    for(int i=0;i<V;i++){
	        // if not colored
	        if(color[i]==-1){
	            //if(bfs(i,V,adj,color)==false) return false;
	            if(dfs(i,0,adj,color)==false) return false;
	        }
	    }
	    return true;
	}

};
