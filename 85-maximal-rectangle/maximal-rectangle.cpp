class Solution {
    int largestarea(vector<int>heights){
      int h = heights.size();
      int maxarea =0;
      stack<int>s;
      for(int i =0; i< h; i++){
        while(!s.empty()and heights[s.top()] > heights[i]){
            int el = heights[s.top()];
            s.pop();
            int nse = i;
            int pse = s.empty() ? -1 :s.top();
            maxarea = max(maxarea,(nse-pse-1)*el);
        }
        s.push(i);
      }
      while(!s.empty()){
          int el = heights[s.top()];
            s.pop();
        int nse = h;
         int pse = s.empty() ? -1 :s.top();
            maxarea = max(maxarea,(nse-pse-1)*el);
      }
return maxarea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
     
        int n = matrix.size();
        int m = matrix[0].size();   
        vector<int>heights(m,0);

        int maximalrect =0;
        for(int i =0 ; i< n; i++){
            for(int j =0; j< m ; j++){
                if (matrix[i][j]=='1'){
                    heights[j]++;

                }
                else{
                    heights[j]=0;
                }
                
            }
             maximalrect = max(maximalrect, largestarea(heights));
        }
        return maximalrect;
    }
};