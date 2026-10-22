class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<vector<int>>adjrev(numCourses);
        
        vector<int>indeg(numCourses,0);
        vector<int>safe;
//    v--->u
       
          for(auto it:  prerequisites){
         int u = it[0];
         int v = it[1];
         adjrev[v].push_back(u);
            indeg[u]++;
          }
        
        queue<int>q;
        for(int i =0 ; i< numCourses ; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            safe.push_back(f);
            for(auto it:adjrev[f] ){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push((it));
                }
            }
        }
        if(safe.size()== numCourses){
            return true;
        }
        else{
            return false;
        }
    }
};