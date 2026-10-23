class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> safe;
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();

            q.pop();
            safe.push_back(node);
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]== 0){
                    q.push(it);
                }
            }
        }
        if(safe.size() != numCourses){
            return {};
        }
        return safe;
    }
};