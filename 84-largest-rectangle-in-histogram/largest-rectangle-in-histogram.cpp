class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int maxarea = 0;
        int n = heights.size();
        for(int i =0; i<n; i++ ){
            while(!s.empty() and heights[i] < heights[s.top()]){
                int el = heights[s.top()];
                s.pop();
               int nse = i;
              
                int pse = s.empty() ? -1 :s.top();
              
             maxarea = max(maxarea,(nse-pse-1)*el);
            }

            s.push(i);

        }
        while(!s.empty()){
            int nse = n;
            int el = heights[s.top()];
            s.pop();
            int pse = s.empty() ? -1 : s.top();
            maxarea = max(maxarea,(nse-pse-1)*el);

        }
        
         return maxarea;
    }

};