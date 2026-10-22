class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis,
             vector<int>& safe, vector<vector<int>>& graph) {
        vis[node] = 1;
        pathvis[node] = 1;
        safe[node] = 0;
        for (auto it : graph[node]) {
            if (vis[it] == 0) {
                safe[node] = 0;
                if(dfs(it,vis,pathvis,safe,graph)){
                    return true;
                }

            } else if (pathvis[it] == 1) {
                safe[node] = 0;
                return true;
            }
        }
        safe[node] = 1;
        pathvis[node]=0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis( V,0);
        vector<int> pathvis( V,0);
        vector<int> ans;
        vector<int> safe(V,0);
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, pathvis, safe, graph);
            }
        }
         for(int i =0 ; i< V ; i++){
            if(safe[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    };