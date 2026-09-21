class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int>st;
        int n = asteroids.size();
        for(int i =0; i< n; i++){
          if(asteroids[i] > 0){
             st.push_back(asteroids[i]);
          }
          else{
            while(!st.empty() and st.back()>0 and st.back()< abs(asteroids[i])){
                st.pop_back();
            }
            if(!st.empty() and st.back() == abs(asteroids[i])){
                st.pop_back();
            }
            else if(st.empty()){
                st.push_back(asteroids[i]);
            }
            else if(st.back()<0){
                st.push_back(asteroids[i]);
            }
          }
            
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};