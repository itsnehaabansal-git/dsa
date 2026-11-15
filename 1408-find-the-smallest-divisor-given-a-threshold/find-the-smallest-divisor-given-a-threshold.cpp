class Solution {
    int sum(int mid, vector<int>& nums){
        int total = 0;
        for(int i = 0 ; i< nums.size(); i++){
          total+= ceil((double(nums[i])/mid));
        }
        return total;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int ans = nums[0];
       for(int i = 1 ; i< nums.size() ; i++){
           if(nums[i]>ans){
            ans = nums[i];
           }
       }
       int high = ans;
       int  finalans =-1;
       while(low<= high){
        int mid = (low+high)/2;
         if((sum(mid,nums)) <= threshold){
            finalans = mid;
            high = mid-1;
         }
         else{
            low = mid+1;
         }

       }
       return finalans;

    }
};