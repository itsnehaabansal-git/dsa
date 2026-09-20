class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
       int l = 0; 
       int r = n-1;
       int lm =0;
       int rm =0;
       int total =0;
       while(l< r){
        if(height[l] <= height[r]){
            if( lm > height[l]){
                total += lm- height[l];
            }
            else{
                lm = height[l];
            }
            l++;
        }
        else{
            if(rm > height[r]){
                total += rm - height[r];
            }
            else{
                rm = height[r];
            }
              r--;
        }
      
       }
       
 return total;
    }
};