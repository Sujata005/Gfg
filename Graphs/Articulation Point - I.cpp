

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int timer=1;
    private:
    void dfs(int node, int parent, vector<int> &vis, int time[], int lowTime[], vector<int> &mark, vector<int> adj[]){
        vis[node]=1;
        time[node]=lowTime[node]=timer;
        timer++;
        int child=0;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,time,lowTime,mark,adj);
                lowTime[node]=min(lowTime[node],lowTime[it]);
                if(lowTime[it]>=time[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                lowTime[node]=min(lowTime[node],time[it]);
            }
        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V,0);
        int time[V];
        int lowTime[V];
        vector<int> mark(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,time,lowTime,mark,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return { -1};
        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
